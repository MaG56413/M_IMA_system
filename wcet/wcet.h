#ifndef WCET_H
#define WCET_H

#include "cpu_context.h"

#include "fault.h"
#include <stdint.h>

/*
 * WCET统计结构
 */
typedef struct
{

    uint32_t count; //执行次数

    uint64_t total_cycle; //总cycle

    uint64_t max_cycle; //最大cycle

    uint64_t min_cycle; //最小cycle

} WCET_Result;

/*
 * 初始化统计数据
 */
void wcet_init(WCET_Result *result);

// 读取时间
uint64_t cycle_counter();

/*
 * 更新统计结果
 */
int wcet_update(WCET_Result *result, uint64_t cycle);

/*
 * 打印结果
 */
void wcet_print(WCET_Result *result);

#endif
