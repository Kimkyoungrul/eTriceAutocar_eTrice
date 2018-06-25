/**
 * @author generated by eTrice
 *
 * Header File of ProtocolClass PTrafficLightController
 * 
 */

#ifndef _TRAFFICLIGHT_PTRAFFICLIGHTCONTROLLER_H_
#define _TRAFFICLIGHT_PTRAFFICLIGHTCONTROLLER_H_

#include "etDatatypes.h"
#include "modelbase/etPort.h"


/* include all referenced room classes */


/* message IDs */
enum PTrafficLightController_msg_ids {
	PTrafficLightController_MSG_MIN = 0,
	PTrafficLightController_OUT_doneStandby = 1,
	PTrafficLightController_OUT_doneStart = 2,
	PTrafficLightController_OUT_doneStop = 3,
	PTrafficLightController_IN_standby = 4,
	PTrafficLightController_IN_start = 5,
	PTrafficLightController_IN_stop = 6,
	PTrafficLightController_MSG_MAX = 7
};

/*--------------------- port structs and methods */
typedef etPort PTrafficLightControllerPort;
typedef etReplPort PTrafficLightControllerReplPort;


void PTrafficLightControllerPort_doneStandby(const PTrafficLightControllerPort* self);
void PTrafficLightControllerReplPort_doneStandby_broadcast(const PTrafficLightControllerReplPort* self);
void PTrafficLightControllerReplPort_doneStandby(const PTrafficLightControllerReplPort* self, int idx);
void PTrafficLightControllerPort_doneStart(const PTrafficLightControllerPort* self);
void PTrafficLightControllerReplPort_doneStart_broadcast(const PTrafficLightControllerReplPort* self);
void PTrafficLightControllerReplPort_doneStart(const PTrafficLightControllerReplPort* self, int idx);
void PTrafficLightControllerPort_doneStop(const PTrafficLightControllerPort* self);
void PTrafficLightControllerReplPort_doneStop_broadcast(const PTrafficLightControllerReplPort* self);
void PTrafficLightControllerReplPort_doneStop(const PTrafficLightControllerReplPort* self, int idx);


etInt32 PTrafficLightControllerReplPort_getReplication(const PTrafficLightControllerReplPort* self);
typedef etPort PTrafficLightControllerConjPort;
typedef etReplPort PTrafficLightControllerConjReplPort;


void PTrafficLightControllerConjPort_standby(const PTrafficLightControllerConjPort* self, int32 data);
void PTrafficLightControllerConjReplPort_standby_broadcast(const PTrafficLightControllerConjReplPort* self, int32 data);
void PTrafficLightControllerConjReplPort_standby(const PTrafficLightControllerConjReplPort* self, int idx, int32 data);
void PTrafficLightControllerConjPort_start(const PTrafficLightControllerConjPort* self);
void PTrafficLightControllerConjReplPort_start_broadcast(const PTrafficLightControllerConjReplPort* self);
void PTrafficLightControllerConjReplPort_start(const PTrafficLightControllerConjReplPort* self, int idx);
void PTrafficLightControllerConjPort_stop(const PTrafficLightControllerConjPort* self);
void PTrafficLightControllerConjReplPort_stop_broadcast(const PTrafficLightControllerConjReplPort* self);
void PTrafficLightControllerConjReplPort_stop(const PTrafficLightControllerConjReplPort* self, int idx);


etInt32 PTrafficLightControllerConjReplPort_getReplication(const PTrafficLightControllerConjReplPort* self);

/*--------------------- debug helpers */

/* get message string for message id */
const char* PTrafficLightController_getMessageString(int msg_id);


#endif /* _TRAFFICLIGHT_PTRAFFICLIGHTCONTROLLER_H_ */
