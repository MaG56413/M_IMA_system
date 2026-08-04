#include <stdio.h>

#include "fault.h"
#include "fault_record.h"
#include "function_map.h"

void capture_fault(CPU_Context *ctx, FaultRecord *record)
{

    record->id = ctx->exception_id;
    record->address = ctx->dar;
    record->pc = ctx->pc;
    record->reason = ctx->dsisr;
    record->type = ctx->exception_type;
    printf("capture_fault\n");
}

void analyze_fault(FaultRecord *record)
{
    const char *name;
    switch (record->type)
    {
    case EXCEPTION_EXTERNAL_INTERRUPT:
        printf("Data Storage Exception\n");
        break;

    case EXCEPTION_MACHINE_CHECK:
        printf("Machine Check Exception\n");
        break;
    case EXCEPTION_DATA_STORAGE:
        printf("Data Storage Exception\n");
        break;
    case EXCEPTION_PROGRAM_ERROR:
        printf("Program Error Exception\n");
        break;
    default:
        printf("Unkonwn\n");
        break;
    }
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
