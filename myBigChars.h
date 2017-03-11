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
//u_int64_t bcZero    = 0b0011110001000010010000100100001001000010010000100100001000111100;
//u_int64_t bcOne     = 0b0000001000000110000010100001001000000010000000100000001000000010;
//u_int64_t bcTwo     = 0b0011110001000010010000100000010000011000001000000100000001111110;
//u_int64_t bcThree   = 0b0011110001000010000000100001110000000010000000100100001000111100;
//u_int64_t bcFour    = 0b0000111000010010001000100010001000111110000000100000001000000010;
//u_int64_t bcFive    = 0b0111111001000000010000000111110000000010000000100100001000111100;
//u_int64_t bcSix     = 0b0011110001000010010000000111110001000010010000100100001000111100;
//u_int64_t bcSeven   = 0b0111111000000010000000100000010000001000000010000000100000001000;
//u_int64_t bcEight   = 0b0011110001000010010000100011110001000010010000100100001000111100;
//u_int64_t bcNine    = 0b0011110001000010010000100011111000000010000000100100001000111100;

enum digits
{
    ZERO    = 0x3C4242424242423C,
    ONE     = 0x02060A1202020202,
    TWO     = 0x3C4242041820407E,
    THREE   = 0x3C42021D0202423C,
    FOUR    ,
};
int bc_printA(char *str);

int bc_box(int x1, int y1, int x2, int y2);

int bc_printbigchar(int *big, int x, int y, enum colors fgcolor, enum colors bgcolor);

int bc_setbigcharpos(int *big, int x, int y, short int value);

int bc_getbigcharpos(int *big, int x, int y, short int *value);

int bc_bigcharwrite(int fd, int *big, int count);

int bc_bigcharread(int fd, int *big, int need_count, int *count);

#endif //ARCHITEC_MYBIGCHARS_H
