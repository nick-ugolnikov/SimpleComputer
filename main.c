#include "myTerm.h"
#include "myBigChars.h"
#include "myGUI.h"
#include "myReadKey.h"
#include "mySimpleComputer.h"

int main()
{
    mt_clrscr();
    rk_mytermregime(0, 0, 1, 0, 1);
//    int file = open("font", O_RDWR | O_CREAT);
//    bc_bigcharwrite(file, font, 18);
    int big[36];
    int cunt = 0;
    int file = open("font", O_RDONLY);
    bc_bigcharread(file, big, 18, &cunt);
    close(file);
    sc_memoryInit();
    for (int i = 0; i < MEM_SIZE; i++)
    {
        sc_memorySet(i, i);
    }
    mg_static();
    mg_interface(big);
    rk_mytermrestore();
    mt_clrscr();
    return 0;
}