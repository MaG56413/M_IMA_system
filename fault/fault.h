#ifndef FAULT_H
#define FAULT_H

#include "cpu_context.h"

void capture_fault(CPU_Context *ctx);

void analyze_fault();

void report_fault();

void fault_handler(
    CPU_Context *ctx);

#endif
