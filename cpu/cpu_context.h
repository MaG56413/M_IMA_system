#ifndef CPU_CONTEXT_H
#define CPU_CONTEXT_H

#include <stdio.h>
#include <stdint.h>

typedef struct
{
    uint32_t pc;
    uint32_t lr;
    uint32_t sp;
    uint32_t status;
    uint32_t exception_id;

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
