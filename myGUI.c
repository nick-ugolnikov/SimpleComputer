//
// Created by nicko on 3/11/17.
//

#include "myGUI.h"
#include "myTerm.h"
#include "myBigChars.h"

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
    mt_setfgcolor(GREEN);
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