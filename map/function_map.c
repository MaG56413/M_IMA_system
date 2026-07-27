#include <stdio.h>

#include "function_map.h"

FunctionMap table[] =
    {

        {0x80000000,
         0x80000FFF,
         "main"},

        {0x80001000,
         0x80001FFF,
         "init"},

        {0x80002000,
         0x80002FFF,
         "irq_handler"}

};

const char *find_function(uint32_t pc)
{
    int size = sizeof(table) / sizeof(table[0]);

    for (int i = 0; i < size; i++)
    {
        if (pc <= table[i].end && pc >= table[i].start)
        {
            return table[i].name;
        }
    }

    return "Unknown \n";
}
