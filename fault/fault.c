#include <stdio.h>

#include "fault.h"
#include "fault_record.h"

void capture_fault(CPU_Context *ctx)
{
    printf("capture_fault\n");
}

void analyze_fault()
{
    printf("analyze_fault\n");
}

void report_fault()
{
    printf("report_fault\n");
}

void fault_handler(CPU_Context *ctx)
{
    FaultRecord record;

    capture_fault(ctx);

    analyze_fault(&record);

    report_fault(&record);

    printf("fault_handler\n");
}
