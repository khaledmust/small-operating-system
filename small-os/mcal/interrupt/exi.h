/*
 * exi.h
 *
 * Created: 2023-05-17 1:37:02 PM
 *  Author: khale
 */ 


#ifndef EXI_H_
#define EXI_H_
#include "../../utilities/registers.h"

void EXI_enable(en_EXI_ExternalInterruptSrc interruptSource);
void EXI_disable(en_EXI_ExternalInterruptSrc interruptSource);
void EXI_triggerEdge(en_EXI_ExternalInterruptSrc interruptSource, en_EXI_SenseControl triggerType);

#endif /* EXI_H_ */