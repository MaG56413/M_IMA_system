#include "wcet.h"

#include <stdio.h>

void wcet_init(
    WCET_Result *result)
{

    result->count = 0;

    result->total_cycle = 0;

    result->max_cycle = 0;

    result->min_cycle = 0xffffffff;
}
