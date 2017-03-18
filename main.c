#include "myTerm.h"
#include "myBigChars.h"
#include "myGUI.h"
#include "mySimpleComputer.h"

int main()
{
    mt_clrscr();
//    int file = open("font", O_RDWR | O_CREAT);
//    bc_bigcharwrite(file, font, 18);
    int big[36];
    int cunt = 0;
    int file = open("font", O_RDONLY);
    bc_bigcharread(file, big, 18, &cunt);
    close(file);
    sc_memoryInit();
    mg_init(big);
    mt_gotoXY(33, 0);
    return 0;
}