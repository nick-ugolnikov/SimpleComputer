#ifndef ARCHITEC_MYTERM_H
#define ARCHITEC_MYTERM_H

#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <memory.h>

enum colors
{
    LIGHT_GREY = 247,
    GREY = 237,
    BLACK = 16,
    RED = 124,
    GREEN = 41,
    BLUE = 20,
    YELLOW = 184,
};

int mt_clrscr(void);

/* производит очистку и перемещение курсора в левый верхний угол экрана; */

int mt_gotoXY(int x, int y);

/*
  перемещает курсор в указанную позицию.
  Первый параметр номер строки, второй - номер столбца;
*/

int mt_getscreensize(int *rows, int *cols);
//определяет размер экрана терминала (количество строк и столбцов);

int mt_setfgcolor(enum colors color);
//устанавливает цвет последующих выводимых
//символов. В качестве параметра передаѐтся константа из созданного Вами перечисли-
//мого типа colors , описывающего цвета терминала;

int mt_setbgcolor(enum colors color);
//устанавливает цвет фона последующих вы-
//водимых символов. В качестве параметра передаѐтся константа из созданного Вами
//перечислимого типа colors , описывающего цвета терминала.
//Все функции возвращают 0 в случае успешного выполнения и -1 в случае ошибки. В каче-
//стве терминала используется стандартный поток вывода.
#endif //ARCHITEC_MYTERM_H
