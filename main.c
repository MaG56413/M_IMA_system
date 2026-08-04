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
    CPU_Context ctx;

    ctx.pc = 0x80001000;
    ctx.lr = 0x80000500;
    ctx.sp = 0x90000000;

    ctx.exception_type = EXCEPTION_DATA_STORAGE;

    exception_handler(&ctx);

    // WCET_Result result;
    // uint64_t start;
    // uint64_t end;
    // uint64_t cycle;

    // init_context(&ctx);
    // wcet_init(&result);
    // for (int i = 0; i < 10; i++)
    // {
    //     start = cycle_counter();
    //     test_task();
    //     end = cycle_counter();
    //     cycle = end - start;

    //     if (wcet_update(&result, cycle))
    //     {
    //         fault_handler(&ctx);
    //     }
    // }

    // printf("cycle=%lu\n", cycle);

    // // exception_entry(&ctx);

    // wcet_print(&result);
    return 0;
}
