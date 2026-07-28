#include <stdio.h>

#include "fault.h"
#include "fault_record.h"
#include "function_map.h"

void capture_fault(CPU_Context *ctx, FaultRecord *record)
{

    record->id = ctx->exception_id;
    record->address = ctx->r0;
    record->pc = ctx->pc;
    record->reason = 500;
    record->type = DATA_ABORT;
    printf("capture_fault\n");
}

void analyze_fault(FaultRecord *record)
{
    const char *name;
    name = find_function(record->pc);
    printf("Function:%s\n", name);

    printf("analyze_fault\n");
}

void report_fault(FaultRecord *record)
{

    print_fault(record);
    printf("report_fault\n");
}

void fault_handler(CPU_Context *ctx)
{
    FaultRecord record;

    capture_fault(ctx, &record);

    analyze_fault(&record);

    report_fault(&record);

    printf("fault_handler\n");
}
