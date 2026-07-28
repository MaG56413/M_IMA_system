#include <stdio.h>
#include "exception/exception.h"
#include "fault/fault_record.h"
#include "map/function_map.h"
#define INVALID_ACCESS 500
int main()
{
    CPU_Context ctx;

    ctx.pc = 0x80002005;

    ctx.lr = 0x1000;

    ctx.sp = 0x90000000;

    ctx.status = 0x9000;

    ctx.exception_id = 0x01;

    ctx.r0 = 0xFFFFFFFF; //模拟非法访问地址

    ctx.r1 = 0x1111;

    ctx.r2 = 0x2222;

    ctx.r3 = 0x3333;

    ctx.r30 = 0x3000;

    ctx.r31 = 0x4000;
    exception_entry(&ctx);
    return 0;
}
