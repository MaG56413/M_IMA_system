#ifndef EXCEPTION_H
#define EXCEPTION_H
#include "cpu_context.h"
#include "exception_type.h"

const char *get_exception_name(ExceptionType type);
void exception_handler(CPU_Context *context);
#endif
