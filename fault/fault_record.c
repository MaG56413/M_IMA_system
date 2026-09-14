#include <stdio.h>
#include <stdlib.h>
#include "fault_record.h"

void print_fault(FaultRecord *record)
{
       // FaultRecord *save_rec;
       // save_rec = (FaultRecord *)malloc(sizeof(FaultRecord));
       // save_rec->address = record->address;
       // save_rec->id = record->id;
       // save_rec->pc = record->pc;
       // save_rec->reason = record->reason;
       // save_rec->type = record->type;
       printf("address:0x%x\n",
              record->address);

       // free(save_rec);
}
