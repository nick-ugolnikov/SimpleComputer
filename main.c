//#include "mySimpleComputer.h"
#include "myTerm.h"
#include "myBigChars.h"
#include "myGUI.h"

int main()
{
    mt_clrscr();
//    int file = open("font", O_RDWR | O_CREAT);
//    bc_bigcharwrite(file, font, 18);
    int big[36];
    int cunt = 0;
    int file = open("font", O_RDONLY);
    bc_bigcharread(file, big, 18, &cunt);
    mg_init(big);
    close(file);
    mt_gotoXY(33, 0);
//    printf("Cunt: %d\n", cunt);
//    printf("File: %d\n", file);
    return 0;
}