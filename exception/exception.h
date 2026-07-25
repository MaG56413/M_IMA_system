#ifndef EXCEPTION_H
#define EXCEPTION_H

typedef enum
{
    RESET,
    DATA_ABORT,
    MACHINE_CHECK,
    PROGRAM_ERROR
} ExceptionType;
const char *get_exception_name(ExceptionType type);
#endif
