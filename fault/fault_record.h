#ifndef FAULT_RECORD_H
#define FAULT_RECORD_H

#include <stdint.h>

#include "exception.h"

typedef struct
{

    uint32_t id;

    ExceptionType type;

    uint32_t pc;

    uint32_t address;

    uint32_t reason;

} FaultRecord;

void print_fault(FaultRecord *record);

#endif
