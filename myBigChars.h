//
// Created by nicko on 3/11/17.
//

#ifndef ARCHITEC_MYBIGCHARS_H
#define ARCHITEC_MYBIGCHARS_H

#include "myTerm.h"

//enter_alt_charset_mode=\E(0
//exit_alt_charset_mode=\E(B
//acs_chars=``aaffggiijjkkllmmnnooppqqrrssttuuvvwwxxyyzz{{||}}~~
//


int digit[10][2] = {{0x4242423C, 0x3C424242},
                    {0x48506040, 0x40404040},
                    {0x2042423C, 0x7E020418},
                    {0x3840423C, 0x3C424040},
                    {0x7E424478, 0x40404040},
                    {0x3E02027E, 0x3C424040},
                    {0x3E02423C, 0x3C424242},
                    {0x2040407E, 0x10101010},
                    {0x3C42423C, 0x3C424242},
                    {0x7C42423C, 0x3C424040}};

int bc_printA(char *str);

int bc_box(int x1, int y1, int x2, int y2);

int bc_printbigchar(int *big, int x, int y, enum colors fgcolor, enum colors bgcolor);

int bc_setbigcharpos(int *big, int x, int y, short int value);

int bc_getbigcharpos(int *big, int x, int y, short int *value);

int bc_bigcharwrite(int fd, int *big, int count);

int bc_bigcharread(int fd, int *big, int need_count, int *count);

#endif //ARCHITEC_MYBIGCHARS_H
