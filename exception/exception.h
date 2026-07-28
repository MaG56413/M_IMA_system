#ifndef EXCEPTION_H
#define EXCEPTION_H
#include "cpu_context.h"

typedef enum
{
    RESET,
    DATA_ABORT,
    MACHINE_CHECK,
    PROGRAM_ERROR
} ExceptionType;
const char *get_exception_name(ExceptionType type);
void exception_handler(CPU_Context *context);
#endif
