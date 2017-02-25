#include "mySimpleComputer.h"

int main()
{
    sc_memoryInit();
    sc_regInit();
    sc_regSet(FLG_TICK_IGNORE, 1);
    sc_memorySet(16, 1488);
    sc_regSet(FLG_TICK_IGNORE, 1);
    int16_t data;
    int8_t regd, regt;
    sc_regGet(FLG_MEMORY_FAULT, &regd);
    sc_regGet(FLG_TICK_IGNORE, &regt);
    sc_memoryGet(16, &data);
    printf("data = %d\nregd = %d\nregt = %d\n", data, regd, regt);
    sc_memorySave("output.txt");
    sc_memoryLoad("output.txt");
    int16_t val;
    sc_commandEncode(16, 4, &val);
    printf("val = %d\n", val);
    int8_t com, op;
    sc_commandDecode(val, &com, &op);
    printf("com = %d\nop = %d\n", com, op);
    return 0;
}