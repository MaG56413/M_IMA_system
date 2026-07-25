#ifndef WCET_H
#define WCET_H

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
void wcet_init(
    WCET_Result *result);

/*
 * 开始计时
 */
uint64_t wcet_start();

/*
 * 结束计时
 */
uint64_t wcet_end(
    uint64_t start);

/*
 * 更新统计结果
 */
void wcet_update(
    WCET_Result *result,
    uint64_t cycle);

/*
 * 打印结果
 */
void wcet_print(
    WCET_Result *result);

#endif
