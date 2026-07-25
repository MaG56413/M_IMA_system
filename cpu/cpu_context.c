#include <stdio.h>
#include <stdlib.h>

#include "cpu_context.h"

CPU_Context *save_context(CPU_Context *context)
{
    CPU_Context *ctx = (CPU_Context *)malloc(sizeof(CPU_Context));
    ctx->exception_id = context->exception_id;
    ctx->lr = context->lr;
    ctx->pc = context->pc;
    ctx->r0 = context->r0;
    ctx->r1 = context->r1;
    ctx->r2 = context->r2;
    ctx->r3 = context->r3;
    ctx->r30 = context->r30;
    ctx->r31 = context->r31;
    ctx->sp = context->sp;
    ctx->status = context->status;

    return ctx;
}

void exception_entry(CPU_Context *ctx)
{

    save_context(ctx);

    exception_handler(ctx);
    free(ctx);
}

void exception_handler(CPU_Context *context)
{
    printf("exception_id: 0x%x \n", context->exception_id);
    printf("lr: 0x%x \n", context->lr);
    printf("sp: 0x%x \n", context->sp);
    printf("status: 0x%x \n", context->status);
    printf("pc: 0x%x \n", context->pc);
    printf("r0: 0x%x \n", context->r0);
    printf("r1: 0x%x \n", context->r1);
    printf("r2: 0x%x \n", context->r2);
    printf("r3: 0x%x \n", context->r3);
    printf("r30: 0x%x \n", context->r30);
    printf("r31: 0x%x \n", context->r31);
}
