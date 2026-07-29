#include "wcet.h"

#include <stdio.h>

#define WCET_LIMIT 7000

uint64_t read_cpu_cycle()
{
    unsigned int low;
    unsigned int high;

    asm volatile(
        "rdtsc"
        : "=a"(low),
          "=d"(high));

    return ((uint64_t)high << 32) | low;
}

void wcet_init(WCET_Result *result)
{

    result->count = 0;

    result->total_cycle = 0;

    result->max_cycle = 0;

    result->min_cycle = 0xffffffff;
}

uint64_t cycle_counter()
{
    return read_cpu_cycle();
}

/*
 * 更新统计结果
 */
int wcet_update(WCET_Result *result, uint64_t cycle)
{
    result->count++;
    if (cycle > result->max_cycle)
    {
        result->max_cycle = cycle;
    }

    if (cycle < result->min_cycle)
    {
        result->min_cycle = cycle;
    }

    result->total_cycle += cycle;
    if (result->max_cycle > WCET_LIMIT)
    {
        return 1;
    }
    return 0;
}

/*
 * 打印结果
 */
void wcet_print(WCET_Result *result)
{
    printf("count:%d\n", result->count);
    printf("max_cycle:%lu\n", result->max_cycle);
    printf("min_cycle:%lu\n", result->min_cycle);
    printf("total_cycle:%lu\n", result->total_cycle);
}
