#ifndef CPU_CONTEXT_H
#define CPU_CONTEXT_H

#include <stdio.h>
#include <stdint.h>

#include "exception_type.h"

#define DSISR_READ_ERROR 0x40000000
#define DSISR_WRITE_ERROR 0x02000000
#define DSISR_PROTECTION 0x08000000
typedef struct
{
    uint32_t pc;
    uint32_t lr;
    uint32_t sp;
    uint32_t status;
    uint32_t exception_id;
    uint32_t dar;
    uint32_t srr1;  // 状态寄存器
    uint32_t dsisr; // 数据异常原因
    ExceptionType exception_type;

    uint32_t r0;
    uint32_t r1;
    uint32_t r2;
    uint32_t r3;
    uint32_t r30;
    uint32_t r31;
} CPU_Context;
void init_context(CPU_Context *ctx);
CPU_Context *save_context(CPU_Context *context);
void exception_entry(CPU_Context *context);
void exception_handler(CPU_Context *context);
#endif
