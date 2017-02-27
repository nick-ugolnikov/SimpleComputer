//
// Created by nicko on 25.02.17.
//

#include "myTerm.h"

int mt_getscreensize (int * rows, int * cols)
{
    struct winsize ws;
    if (!ioctl(1, TIOCGWINSZ, &ws))
    {
        *rows = ws.ws_row;
        *cols = ws.ws_col;
        printf ("Получен размер экрана.\n");
        printf ("Число строк – %d\nЧисло столбцов – %d\n",
                ws.ws_row, ws.ws_col);
    } else
    {
        fprintf (stderr, "Ошибка получения размера экрана.\n");
        return -1;
    }
    return 0;
}