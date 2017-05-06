//
// Created by nicko on 3/11/17.
//

#ifndef ARCHITEC_MYGUI_H
#define ARCHITEC_MYGUI_H

#include <sys/param.h>

#define BC_X 15
#define BC_START 8
#define BC_STEP 8
#define X_START 2
#define Y_START 3
#define Y_STEP 6

void mg_memorybox();

void mg_accumbox();

void mg_counterbox();

void mg_operationbox();

void mg_flagbox();

void mg_bcbox(int *big);

void mg_init(int *big);

void mg_static();

void mg_interface(int *big);

void mg_loadmemory();

void mg_savememory();

void mg_setmemory(int x, int y);

void mg_printmemory(int *x, int *y);

void mg_printbc(int x, int y);

#endif //ARCHITEC_MYGUI_H
