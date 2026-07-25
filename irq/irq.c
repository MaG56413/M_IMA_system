#include <stdio.h>

#include "irq.h"

volatile int irq_status = 0;

void ISR(uint32_t source)
{
    irq_status |= source;
}
