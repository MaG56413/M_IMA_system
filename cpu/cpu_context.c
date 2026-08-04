#include <stdio.h>
#include <stdlib.h>

#include "cpu_context.h"

// exceptions handle steps
//
//  CPU_Context ctx
//          |
//          |
//  exception_entry(ctx)
//          |
//          |
//  save_context()
//          |
//          |
//  保存一份现场
//          |
//          |
//  exception_handler()
//          |
//          |
//  分析异常
void init_context(CPU_Context *ctx)
{
    ctx->pc = 0x80002005;

    ctx->lr = 0x80000000;

    ctx->sp = 0x90000000;

    ctx->status = 0x9000;

    ctx->srr1 = 0x00009000;

    ctx->dar = 0x00000000;

    ctx->dsisr = DSISR_WRITE_ERROR;

    ctx->exception_id = 0x01;

    ctx->r0 = 0xFFFFFFFF; //模拟非法访问地址

    ctx->r1 = 0x1111;

    ctx->r2 = 0x2222;

    ctx->r3 = 0x3333;

    ctx->r30 = 0x3000;

    ctx->r31 = 0x4000;
}

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
    CPU_Context *save;

    save = save_context(ctx);

    exception_handler(save);
    free(save);
}

// void exception_handler(CPU_Context *context)
// {
//     printf("exception_id: 0x%x \n", context->exception_id);
//     printf("lr: 0x%x \n", context->lr);
//     printf("sp: 0x%x \n", context->sp);
//     printf("status: 0x%x \n", context->status);
//     printf("pc: 0x%x \n", context->pc);
//     printf("r0: 0x%x \n", context->r0);
//     printf("r1: 0x%x \n", context->r1);
//     printf("r2: 0x%x \n", context->r2);
//     printf("r3: 0x%x \n", context->r3);
//     printf("r30: 0x%x \n", context->r30);
//     printf("r31: 0x%x \n", context->r31);
// }

//             CPU现场

//               |
//               v

//          exception_entry()

//               |
//               v

//          save_context()

//               |
//               v

//    malloc保存一份现场

//               |
//               v

//         save(CPU_Context)

//               |
//               v

//       exception_handler()

//               |
//               v

//          异常分析

//               |
//               v

//           free(save)
