#ifndef FUNCTION_MAP_H
#define FUNCTION_MAP_H
#include <stdint.h>
const char *find_function(uint32_t pc);

typedef struct
{

    uint32_t start;

    uint32_t end;

    char name[32];

} FunctionMap;
#endif
