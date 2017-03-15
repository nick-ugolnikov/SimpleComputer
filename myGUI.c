//
// Created by nicko on 3/11/17.
//

#include "myGUI.h"
#include "myTerm.h"
#include "myBigChars.h"

int digit[18][2] = {{0x4242423C, 0x3C424242},  // 0
                    {0x48506040, 0x40404040},  // 1
                    {0x2042423C, 0x7E020418},  // 2
                    {0x3840423C, 0x3C424040},  // 3
                    {0x7E424478, 0x40404040},  // 4
                    {0x3E02027E, 0x3C424040},  // 5
                    {0x3E02423C, 0x3C424242},  // 6
                    {0x2040407E, 0x10101010},  // 7
                    {0x3C42423C, 0x3C424242},  // 8
                    {0x7C42423C, 0x3C424040},  // 9
                    {0x66663C18, 0x66667E7E},  // A
                    {0x3E66663E, 0x3E666666},  // B
                    {0x0202423C, 0x3C420202},  // C
                    {0x4444443E, 0x3E444444},  // D
                    {0x3E02027E, 0x7E020202},  // E
                    {0x1E02027E, 0x02020202},  // F
                    {0x7E181800, 0x0018187E},  // +
                    {0x00181800, 0x00181800}}; // :

void mg_memorybox()
{
    mt_setbgcolor(GREY);
    mt_setfgcolor(YELLOW);
    bc_box(1, 1, 14, 63);
    mt_gotoXY(0, 28);
    write(STDOUT_FILENO, " Memory ", 8 * sizeof(char));
    mt_setfgcolor(GREEN);
    for (int j = 3; j < 63; j += 6)
    {
        for (int i = 2; i < 14; ++i)
        {
            mt_gotoXY(i, j);
            write(STDOUT_FILENO, "+0000 ", 6 * sizeof(char));
        }
    }
    mt_gotoXY(33, 0);
}

void mg_accumbox()
{
    mt_setbgcolor(GREY);
    mt_setfgcolor(YELLOW);
    bc_box(1, 64, 4, 39);
    mt_gotoXY(1, 77);
    write(STDOUT_FILENO, " accumulator ", 13 * sizeof(char));
    mt_setfgcolor(GREEN);
    mt_gotoXY(2, 80);
    write(STDOUT_FILENO, "+9999", 5 * sizeof(char));
    mt_gotoXY(33, 0);
}

void mg_counterbox()
{
    mt_setbgcolor(GREY);
    mt_setfgcolor(YELLOW);
    bc_box(5, 64, 3, 39);
    mt_gotoXY(5, 73);
    write(STDOUT_FILENO, " instructionCounter ", 20 * sizeof(char));
    mt_setfgcolor(GREEN);
    mt_gotoXY(6, 80);
    write(STDOUT_FILENO, "+0000", 5 * sizeof(char));
    mt_gotoXY(33, 0);
}

void mg_operationbox()
{
    mt_setbgcolor(GREY);
    mt_setfgcolor(YELLOW);
    bc_box(8, 64, 4, 39);
    mt_gotoXY(8, 78);
    write(STDOUT_FILENO, " Operation ", 11 * sizeof(char));
    mt_setfgcolor(GREEN);
    mt_gotoXY(9, 79);
    write(STDOUT_FILENO, "+00 : 00", 8 * sizeof(char));
    mt_gotoXY(33, 0);
}

void mg_flagbox()
{
    mt_setbgcolor(GREY);
    mt_setfgcolor(YELLOW);
    bc_box(12, 64, 3, 39);
    mt_gotoXY(12, 79);
    write(STDOUT_FILENO, " Flags ", 7 * sizeof(char));
    mt_setfgcolor(GREEN);
    mt_gotoXY(13, 79);
    write(STDOUT_FILENO, "O E V M", 7 * sizeof(char));
    mt_gotoXY(33, 0);
}

void mg_keybox()
{
    mt_setbgcolor(GREY);
    mt_setfgcolor(YELLOW);
    bc_box(15, 64, 14, 39);
    mt_gotoXY(15, 67);
    write(STDOUT_FILENO, " Keys ", 7 * sizeof(char));
    mt_setfgcolor(GREEN);
    char *str[7] = {"l - load", "s - save", "r - run", "t - step", "i - reset", "F5 - accumulator", "F6 - instructionCounter"};
    for (int i = 0; i < 7; i++)
    {
        mt_gotoXY(16 + i, 66);
        write(STDOUT_FILENO, str[i], strlen(str[i]));
    }
    mt_gotoXY(33, 0);
}

void mg_bcbox()
{
    mt_setbgcolor(GREY);
    mt_setfgcolor(YELLOW);
    bc_box(15, 1, 14, 63);
    bc_printbigchar(digit[17], 16, 2, GREEN, GREY);
    mt_gotoXY(33, 0);
}

void mg_init()
{
    mg_memorybox();
    mg_accumbox();
    mg_counterbox();
    mg_operationbox();
    mg_flagbox();
    mg_keybox();
    mg_bcbox();
}