/**
 * @author generated by eTrice
 *
 * Utils File of ProtocolClass PInterrupt
 * 
 */

#ifndef _ROOM_BASIC_SERVICE_PINTERRUPT_PINTERRUPT_UTILS_H_
#define _ROOM_BASIC_SERVICE_PINTERRUPT_PINTERRUPT_UTILS_H_

#include "room/basic/service/pinterrupt/PInterrupt.h"

/*
 * access macros for operations and attributes
*/

/* conjugate port class */

/* operations */
#define export() PInterruptConjPort_export(self)
#define dispatch() PInterruptConjPort_dispatch(self)
#define fire() PInterruptConjPort_fire(self)

/* attributes */
#define msg (((PInterruptConjPort_var*)(self->varData))->msg)
#define callback (((PInterruptConjPort_var*)(self->varData))->callback)
#define enable (((PInterruptConjPort_var*)(self->varData))->enable)

#endif /* _ROOM_BASIC_SERVICE_PINTERRUPT_PINTERRUPT_UTILS_H_ */
