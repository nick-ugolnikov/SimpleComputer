//
// Created by nicko on 3/11/17.
//

#include "myGUI.h"
#include "myTerm.h"
#include "myBigChars.h"
#include "mySimpleComputer.h"
#include "myReadKey.h"

//int digit[18][2] = {{0x4242423C, 0x3C424242},  // 0
//                    {0x48506040, 0x40404040},  // 1
//                    {0x2042423C, 0x7E020418},  // 2
//                    {0x3840423C, 0x3C424040},  // 3
//                    {0x7E424478, 0x40404040},  // 4
//                    {0x3E02027E, 0x3C424040},  // 5
//                    {0x3E02423C, 0x3C424242},  // 6
//                    {0x2040407E, 0x10101010},  // 7
//                    {0x3C42423C, 0x3C424242},  // 8
//                    {0x7C42423C, 0x3C424040},  // 9
//                    {0x66663C18, 0x66667E7E},  // A
//                    {0x3E66663E, 0x3E666666},  // B
//                    {0x0202423C, 0x3C420202},  // C
//                    {0x4444443E, 0x3E444444},  // D
//                    {0x3E02027E, 0x7E020202},  // E
//                    {0x1E02027E, 0x02020202},  // F
//                    {0x7E181800, 0x0018187E},  // +
//                    {0x00181800, 0x00181800}}; // :

void mg_static()
{
    mt_setbgcolor(GREY);
    mt_setfgcolor(YELLOW);

    bc_box(1, 1, 12, 63);
    mt_gotoXY(0, 28);
    write(STDOUT_FILENO, " Memory ", 8 * sizeof(char));

    bc_box(1, 64, 3, 39);
    mt_gotoXY(1, 77);
    write(STDOUT_FILENO, " accumulator ", 13 * sizeof(char));

    bc_box(4, 64, 3, 39);
    mt_gotoXY(4, 73);
    write(STDOUT_FILENO, " instructionCounter ", 20 * sizeof(char));

    bc_box(7, 64, 3, 39);
    mt_gotoXY(7, 78);
    write(STDOUT_FILENO, " Operation ", 11 * sizeof(char));

    bc_box(10, 64, 3, 39);
    mt_gotoXY(10, 79);
    write(STDOUT_FILENO, " Flags ", 7 * sizeof(char));

    bc_box(13, 1, 12, 63);

    bc_box(13, 64, 12, 39);
    mt_gotoXY(13, 67);
    write(STDOUT_FILENO, " Keys ", 7 * sizeof(char));
    mt_setfgcolor(GREEN);
    char *str[7] = {"l - load", "s - save", "r - run", "t - step", "i - reset", "F5 - accumulator",
                    "F6 - instructionCounter"};
    for (int i = 0; i < 7; i++)
    {
        mt_gotoXY(15 + i, 66);
        write(STDOUT_FILENO, str[i], strlen(str[i]));
    }

    mt_gotoXY(33, 0);
}

void mg_memorybox()
{
    mt_setbgcolor(GREY);
    mt_setfgcolor(GREEN);
    int k = 0;
    for (int j = Y_START; j < 63; j += Y_STEP)
    {
        for (int i = X_START; i < 12; ++i)
        {
            mt_gotoXY(i, j);
            char buf[6];
            int16_t val;
            sc_memoryGet(k++, &val);
            sprintf(buf, "%04d", val);
            write(STDOUT_FILENO, buf, 5 * sizeof(char));
        }
    }
}

void mg_accumbox()
{
    mt_setbgcolor(GREY);
    mt_setfgcolor(GREEN);
    mt_gotoXY(2, 80);
    char buf[5];
    int16_t val;
    sc_accumGet(&val);
    sprintf(buf, "%04x", val);
    write(STDOUT_FILENO, buf, 5 * sizeof(char));
    mt_gotoXY(33, 0);
}

void mg_counterbox()
{
    mt_setbgcolor(GREY);
    mt_setfgcolor(GREEN);
    mt_gotoXY(5, 80);
    char buf[5];
    u_int8_t val;
    sc_countGet(&val);
    sprintf(buf, "%04x", val);
    write(STDOUT_FILENO, buf, 5 * sizeof(char));
    mt_gotoXY(33, 0);
}

void mg_operationbox()
{
    mt_setbgcolor(GREY);
    mt_setfgcolor(GREEN);
    mt_gotoXY(8, 79);
    write(STDOUT_FILENO, "+00 : 00", 8 * sizeof(char));
    mt_gotoXY(33, 0);
}

void mg_flagbox()
{
    mt_setbgcolor(GREY);
    mt_setfgcolor(GREEN);
    mt_gotoXY(11, 79);
    write(STDOUT_FILENO, "O E V M", 7 * sizeof(char));
    mt_gotoXY(33, 0);
}


void mg_bcbox(int *big)
{
    for (int i = 0; i < 6; i++)
    {
        int digit[2] = {big[2 * i], big[2 * i + 1]};
        bc_printbigchar(digit, BC_X, BC_START + i * BC_STEP, GREEN, GREY);
    }
//    int digit[2] = {big[0], big[1]};
//    bc_printbigchar(digit, BC_X, BC_START + BC_STEP, GREEN, GREY);
    mt_gotoXY(33, 0);
}

void mg_init(int *big)
{
    mg_accumbox();
    mg_counterbox();
    mg_operationbox();
    mg_flagbox();
    mg_bcbox(big);
    mg_memorybox();
}

void mg_interface(int *big)
{
    int exit = 0;
    int x = 0, y = 0, cnt = 0;
    mg_static();
    while (!exit)
    {
        enum keys key = KEY_DEFAULT;
        mg_init(big);
        mg_memorybox();
        mg_printmemory(&x, &y);
        rk_readkey(&key);
//        if (key == KEY_ESCAPE)
//            exit++;
//        if (key == KEY_L)
//            mg_loadmemory();
//        if (key == KEY_S)
//            mg_savememory();
        if (key == KEY_UP)
            x--;
        if (key == KEY_DOWN)
            x++;
        if (key == KEY_LEFT)
            y--;
        if (key == KEY_RIGHT)
            y++;
//        if (key == KEY_I)
//        {
//            sc_memoryInit();
//            x = 0, y = 0;
//            mg_static();
//        }
//        if (key == KEY_F5)
//            set_accum();
//        if (key == KEY_F6)
//            set_instcnt();
//        if (key == KEY_R)
//            run(&x, &y);
//        if (key == KEY_T)
//            step(&x, &y);
        if (key == KEY_ENTER)
            mg_setmemory(x, y);
        if (cnt == 5)
        {
            mt_setbgcolor(GREY);
            mg_static();
            cnt = 0;
        }
        cnt++;
//        mt_gotoXY(x, y);
    }
}

void mg_loadmemory()
{
    bc_box(20, 6, 20, 5);
    mt_gotoXY(24, 7);
    write(1, "Load\n", strlen("Load\n"));
    char tmp[255] = "\0";
    mt_gotoXY(21, 9);
    read(1, tmp, 255);
    tmp[strlen(tmp) - 1] = '\0';
    if (sc_memoryLoad(tmp)) {
        bc_box(20, 6, 20, 5);
        mt_gotoXY(23, 7);
        write(1, "Failed to open\n", strlen("Failed to open\n"));
        mt_gotoXY(29, 9);
        mt_setbgcolor(GREY);
        write(1, "OK", strlen("OK"));
        mt_setbgcolor(GREEN);
        mt_gotoXY(30, 9);
        read(1, tmp, 1);
    }
    mg_static();
}

void mg_savememory()
{
    bc_box(20, 6, 20, 5);
    mt_gotoXY(23, 7);
    write(1, "Save to\n", strlen("Save to\n"));
    char tmp[255] = "\0";
    mt_gotoXY(21, 9);
    read(1, tmp, 255);
    tmp[strlen(tmp) - 1] = '\0';
    if (sc_memorySave(tmp)) {
        bc_box(20, 6, 20, 5);
        mt_gotoXY(23, 7);
        write(1, "Failed to save\n", strlen("Failed to open\n"));
        mt_gotoXY(29, 9);
        mt_setbgcolor(YELLOW);
        write(1, "OK", strlen("OK"));
        mt_setbgcolor(GREEN);
        mt_gotoXY(30, 9);
        read(1, tmp, 1);
    }
    mg_static();
}

//void mg_printmemory(int *x, int *y)
//{
//    for (int i = 0; i < 100; i++) {
//        mt_gotoXY(X_START + 6 * (i / 10), Y_START + (i % 10));
//        if (*x > 9)
//            *x = 0;
//        if (*x < 0)
//            *x = 9;
//        if (*y > 9)
//            *y = 0;
//        if (*y < 0)
//            *y = 9;
//        if (i / 10 == *y && i % 10 == *x)
//            mt_setbgcolor(BLUE);
//        int16_t value;
//        int8_t command, operand;
//        sc_memoryGet(i, &value);
//        sc_commandDecode(value, &command, &operand);
//        char tmp1[10];
//        if (command < 16 && operand < 16)
//            sprintf(tmp1, "0%x:0%x", command, operand);
//        else if (command < 16 && operand >= 16)
//            sprintf(tmp1, "0%x:%x", command, operand);
//        else if (command >= 16 && operand < 16)
//            sprintf(tmp1, "%x:0%x", command, operand);
//        else
//            sprintf(tmp1, "%x:%x", command, operand);
//        write(1, tmp1, strlen(tmp1));
//        mt_setbgcolor(GREEN);
//    }
//}

void mg_printmemory(int *x, int *y)
{
    if (*x > 9)
        *x = 0;
    if (*x < 0)
    {
        mg_memorybox();
        *x = 9;
    }
    if (*y > 9)
        *y = 0;
    if (*y < 0)
    {
        mg_memorybox();
        *y = 9;
    }
    mt_gotoXY(X_START + (*x), Y_START + (*y) * Y_STEP);
    mt_setbgcolor(BLUE);
    int16_t value;
    int8_t address = (*x) + (*y) * 10;
    sc_memoryGet(address, &value);
    char tmp[5];
    sprintf(tmp, "%04d", value);
    write(STDOUT_FILENO, tmp, 5 * sizeof(char));
}

//void mg_printbc(int x, int y, int *big)
//{
//    int16_t value;
//    int8_t command, operand;
//    sc_memoryGet(10 * y + x, &value);
//    sc_commandDecode(value, &command, &operand);
//    int big0[] = {big[command / 16 * 2], big[command / 16 * 2 + 1]};
//    bc_printbigchar(big0, BC_X, BC_START + BC_STEP * 0, GREEN, GREY);
//    int big1[] = {big[command % 16 * 2], big[command % 16 * 2 + 1]};
//    bc_printbigchar(big1, BC_X, BC_START + BC_STEP * 1, GREEN, GREY);
//    int big2[] = {big[16 * 2], big[16 * 2 + 1]};
//    bc_printbigchar(big2, BC_X, BC_START + BC_STEP * 2, GREEN, GREY);
//    int big3[] = {big[operand / 16 * 2], big[operand / 16 * 2 + 1]};
//    bc_printbigchar(big3, BC_X, BC_START + BC_STEP * 3, GREEN, GREY);
//    int big4[] = {big[operand % 16 * 2], big[operand % 16 * 2 + 1]};
//    bc_printbigchar(big4, BC_X, BC_START + BC_STEP * 4, GREEN, GREY);
//}

void mg_setmemory(int x, int y)
{
//    bc_box(20, 6, 26, 5);
    bc_box(6, 20, 3, 26);
    mt_gotoXY(6, 24);
    write(STDOUT_FILENO, "Set memory(dec) to\n", strlen("Set memory(dec) to\n"));
    char tmp[11] = "\0";
    mt_gotoXY(7, 21);
    read(1, tmp, 10);
    tmp[strlen(tmp) - 1] = '\0';
    int tmp1 = atoi(tmp);
    sc_memorySet(10 * y + x, tmp1);
    mg_static();
    mg_memorybox();
}