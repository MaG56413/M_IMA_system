#include <stdio.h>
#include "exception/exception.h"
#include "fault/fault_record.h"
#include "map/function_map.h"
#define INVALID_ACCESS 500
int main()
{
    FaultRecord record;
    record.address = 0xFFFFFFFF;
    record.id = 1;
    record.pc = 0x80001000;
    record.reason = INVALID_ACCESS;
    record.type = DATA_ABORT;
    uint32_t pc = 0x2005;
    print_fault(&record);

    const char *name = find_function(record.pc);
    printf("Function: %s\n", name);
    find_function(pc);
    printf("IMA System Start.\n");
    return 0;
}
