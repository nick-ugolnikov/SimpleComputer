//
// Created by nicko on 11.02.17.
//

#include "mySimpleComputer.h"

int sc_memoryInit ()
{
    memset(mem, 0, MEM_SIZE * sizeof(mem[0]));
    return 0;
}

int sc_memorySet (int8_t address, int16_t value)
{
    if ((address < 100) && (address >= 0))
        mem[address] = value;
    else
    {
        sc_regSet(FLG_MEMORY_FAULT, 1);
        return ADDRESS_ERROR;
    }
    return 0;
}

int sc_memoryGet (int8_t address, int16_t * value)
{
    if ((address < 100) && (address >= 0))
        *value = mem[address];
    else
    {
        sc_regSet(FLG_MEMORY_FAULT, 1);
        return ADDRESS_ERROR;
    }
    return 0;
}

int sc_memorySave (char * filename)
{
    FILE *ptrsave = fopen(filename, "wb");
    if (ptrsave !=  NULL)
    {
        fwrite(mem, sizeof(mem[0]), MEM_SIZE, ptrsave);
        fclose(ptrsave);
    } else return FILE_ERROR;
    return 0;
}

int sc_memoryLoad (char * filename)
{
    FILE *ptrload = fopen(filename, "rb");
    if (ptrload != NULL)
    {
        fread(mem, sizeof(mem[0]), MEM_SIZE, ptrload);
        fclose(ptrload);
    } else return FILE_ERROR;
    return 0;
}

int sc_regInit (void)
{
    reg.accum = 0;
    reg.count = 0;
    reg.flg = 0b00000000;
}

int sc_regSet (int8_t regist, int8_t value)
{
    if (value == 1)
    {
        switch (regist)
        {
            case FLG_OVERFLOW:
                reg.flg |= FLG_OVERFLOW;
                break;
            case FLG_ZERO_DIVISION:
                reg.flg |= FLG_ZERO_DIVISION;
                break;
            case FLG_MEMORY_FAULT:
                reg.flg |= FLG_MEMORY_FAULT;
                break;
            case FLG_TICK_IGNORE:
                reg.flg |= FLG_TICK_IGNORE;
                break;
            case FLG_WRONG_COMMAND:
                reg.flg |= FLG_WRONG_COMMAND;
                break;
            default:
                return REG_ERROR;
        }
    }
    else if (value == 0)
        {
            switch (regist)
            {
                case FLG_OVERFLOW:
                    reg.flg &= ~FLG_OVERFLOW;
                    break;
                case FLG_ZERO_DIVISION:
                    reg.flg &= ~FLG_ZERO_DIVISION;
                    break;
                case FLG_MEMORY_FAULT:
                    reg.flg &= ~FLG_MEMORY_FAULT;
                    break;
                case FLG_TICK_IGNORE:
                    reg.flg &= ~FLG_TICK_IGNORE;
                    break;
                case FLG_WRONG_COMMAND:
                    reg.flg &= ~FLG_WRONG_COMMAND;
                    break;
                default:
                    return REG_ERROR;
            }
        }
    else
        return REG_ERROR;
    return 0;
}

int sc_regGet (int8_t regist, int8_t * value)
{
    switch (regist)
    {
        case FLG_OVERFLOW:
            *value = (reg.flg & FLG_OVERFLOW) > 0 ? 1 : 0;
            break;
        case FLG_ZERO_DIVISION:
            *value = (reg.flg & FLG_ZERO_DIVISION) > 0 ? 1 : 0;
            break;
        case FLG_MEMORY_FAULT:
            *value = (reg.flg & FLG_MEMORY_FAULT) > 0 ? 1 : 0;
            break;
        case FLG_TICK_IGNORE:
            *value = (reg.flg & FLG_TICK_IGNORE) > 0 ? 1 : 0;
            break;
        case FLG_WRONG_COMMAND:
            *value = (reg.flg & FLG_WRONG_COMMAND) > 0 ? 1 : 0;
            break;
        default:
            return REG_ERROR;
    }
}

int sc_commandEncode (int8_t command, int8_t operand, int16_t * value)
{
    u_int16_t tmp = 0b0000000000000000;
    tmp |= operand;
    tmp <<= 7;
    tmp |= command;
    tmp |= 0 << 14;
    *value = tmp;
    return 0;
}


int sc_commandDecode (int16_t value, int8_t * command, int8_t * operand) {
    if ((value & (1 << 14)) != 0)
    {
        sc_regSet(FLG_WRONG_COMMAND, 1);
        return COMMAND_ERROR;
    }
    *command = (int8_t)(value);
    *command &= ~(1 << 7);
    *operand = (int8_t)(value >> 7);
    return 0;
}
