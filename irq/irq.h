#ifndef IRQ_H
#define IRQ_H
#include <stdint.h>

extern volatile int irq_status;
volatile int rx_ready;
void ISR(uint32_t source);

#endif
