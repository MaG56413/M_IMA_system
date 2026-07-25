#include <stdio.h>

#include "exception.h"

const char *exception_name[] =
    {"Reset",
     "Data Abort",
     "Machine Check",
     "Program Error"};

const char *get_exception_name(ExceptionType type)
{

    if (type <= PROGRAM_ERROR)
    {
        return exception_name[type];
    }

    return "Unknown";
}
