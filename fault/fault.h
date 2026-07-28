#ifndef FAULT_H
#define FAULT_H

#include "cpu_context.h"
#include "fault_record.h"

void capture_fault(CPU_Context *ctx, FaultRecord *record);

void analyze_fault(FaultRecord *record);

void report_fault(FaultRecord *record);

void fault_handler(CPU_Context *ctx);

#endif
