//
// Created by nicko on 11.02.17.
//

#ifndef SIMPLECOMPUTER_MYSIMPLECOMPUTER_H
#define SIMPLECOMPUTER_MYSIMPLECOMPUTER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MEM_SIZE 100

typedef enum
{
    FLG_OVERFLOW = 0b00000001, // 1
    FLG_ZERO_DIVISION = 0b00000010, // 2
    FLG_MEMORY_FAULT = 0b00000100, // 4
    FLG_TICK_IGNORE = 0b00001000, // 8
    FLG_WRONG_COMMAND = 0b00010000 // 16
} flg_t;

typedef struct
{
    u_int16_t accum;
    u_int8_t count;
    u_int8_t flg;
} reg_t;

enum err_num
{
    ADDRESS_ERROR = 1,
    FILE_ERROR,
    REG_ERROR,
    COMMAND_ERROR,
};


int sc_memoryInit ();

int sc_memorySet (int8_t address, int16_t value);

int sc_memoryGet (int8_t address, int16_t * value);

int sc_memorySave (char * filename);

int sc_memoryLoad (char * filename);

int sc_regInit (void);

int sc_regSet (int8_t regist, int8_t value);

int sc_regGet (int8_t regist, int8_t * value);

int sc_commandEncode (int8_t command, int8_t operand, int16_t * value);

int sc_commandDecode (int16_t value, int8_t * command, int8_t * operand);

#endif //SIMPLECOMPUTER_MYSIMPLECOMPUTER_H
