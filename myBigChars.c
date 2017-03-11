//
// Created by nicko on 3/11/17.
//

#include "myBigChars.h"

int bc_printA(char *str)
{
    ssize_t len = strlen(str) * sizeof(char);
    write(STDOUT_FILENO, "\E(0", 3);
    if (write(STDOUT_FILENO, str, len) != len)
    {
        return -1;
    }
    write(STDOUT_FILENO, "\E(B", 3);
    return 0;
}

int bc_box(int x1, int y1, int x2, int y2)
{
    for (int i = 0; i < x2; i++)
    {
        for (int j = 0; j < y2; j++)
        {
            mt_gotoXY(x1 + i, y1 + j);

            //corners
            if (i == 0 && j == 0)
                bc_printA("l");
            else if (i == 0 && j == y2 - 1)
                bc_printA("k\n");
            else if (i == x2 - 1 && j == 0)
                bc_printA("m");
            else if (i == x2 - 1 && j == y2 - 1)
                bc_printA("j\n");
            else if ( (i == 0 || i == x2 - 1) && (j > 0 && j < y2) ) // horizontal line
                bc_printA("q");
            else if ( (i > 0 && i < x2) && (j == 0 || j == y2 -1)) // vertical line
                bc_printA("x");
            else
                write(STDOUT_FILENO, " ", sizeof(char));
        }
    }
    return 0;
}