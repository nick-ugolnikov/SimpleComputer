//
// Created by nicko on 11.02.17.
//

#ifndef SIMPLECOMPUTER_MYSIMPLECOMPUTER_H
#define SIMPLECOMPUTER_MYSIMPLECOMPUTER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MEM_SIZE 100

u_int16_t mem[MEM_SIZE];

typedef enum
{
    FLG_DEFAULT,
    FLG_OVERFLOW,
    FLG_ZERO_DIVISION,
    FLG_MEMORY_FAULT,
    FLG_TICK_IGNORE,
    FLG_WRONG_COMMAND
} flg_t;

typedef struct
{
    u_int16_t accum;
    u_int8_t count;
    flg_t flg;
} reg_t;

reg_t reg;

enum err_num
{
    ADDRESS_ERROR = 1,
    FILE_ERROR,
};


int sc_memoryInit ();

int sc_memorySet (u_int8_t address, u_int16_t value);

int sc_memoryGet (u_int8_t address, u_int16_t * value);

int sc_memorySave (char * filename);

int sc_memoryLoad (char * filename);

int sc_regInit (void);

int sc_regSet (int register, int value);

int sc_regGet (int register, int * value);

int sc_commandEncode (int command, int operand, int * value);

int sc_commandDecode (int value, int * command, int * operand);

#endif //SIMPLECOMPUTER_MYSIMPLECOMPUTER_H
