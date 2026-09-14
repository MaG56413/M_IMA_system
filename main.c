#include <stdio.h>
#include "exception/exception.h"
#include "fault/fault_record.h"
#include "map/function_map.h"
#include "wcet.h"
#define INVALID_ACCESS 500

void test_task()
{
    volatile int i;
    for (i = 0; i < 10000; i++)
    {
    }
}

int main()
{
    CPU_Context ctx = {0};

    ctx.pc = 0x80001000;

    ctx.lr = 0x80000500;

    ctx.sp = 0x90000000;

    ctx.exception_id = 1;

    ctx.dar = 0x00000000;

    ctx.dsisr = 0x02000000;

    ctx.srr1 = 0x00008000;

    ctx.exception_type = EXCEPTION_DATA_STORAGE;

    fault_handler(&ctx);

    return 0;
}
