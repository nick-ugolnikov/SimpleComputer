//
// Created by nicko on 3/11/17.
//

#ifndef ARCHITEC_MYGUI_H
#define ARCHITEC_MYGUI_H

enum bc_position
{
    BC_X = 16,
    BC_START = 2,
    BC_STEP = 8
};

void mg_memorybox();

void mg_accumbox();

void mg_counterbox();

void mg_operationbox();

void mg_flagbox();

void mg_keybox();

void mg_bcbox(int *big);

void mg_init(int *big);

#endif //ARCHITEC_MYGUI_H
