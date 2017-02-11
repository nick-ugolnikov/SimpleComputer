//
// Created by nicko on 11.02.17.
//

#include "mySimpleComputer.h"

int sc_memoryInit ()
{
    memset(mem, 0, MEM_SIZE * sizeof(mem[0]));
    return 0;
}

int sc_memorySet (u_int8_t address, u_int16_t value)
{
    if ((address < 100) && (address >= 0))
        mem[address] = value;
    else return ADDRESS_ERROR;
    return 0;
}

int sc_memoryGet (u_int8_t address, u_int16_t * value)
{
    if ((address < 100) && (address >= 0))
        *value = mem[address];
    else return ADDRESS_ERROR;
    return 0;
}

int sc_memorySave (char * filename)
{
    FILE *ptrsave = fopen(filename, wb);
    if (ptrsave !=  NULL)
    {
        fwrite(mem, sizeof(mem[0]), MEM_SIZE, ptrsave);
        fclose(ptrsave);
    } else return FILE_ERROR;
    return 0;
}

int sc_memoryLoad (char * filename)
{
    FILE *ptrload = fopen(filename, rb);
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
    reg.flg = FLG_DEFAULT;
}

