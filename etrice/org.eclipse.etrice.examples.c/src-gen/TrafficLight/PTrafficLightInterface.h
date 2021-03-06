/**
 * @author generated by eTrice
 *
 * Header File of ProtocolClass PTrafficLightInterface
 * 
 */

#ifndef _TRAFFICLIGHT_PTRAFFICLIGHTINTERFACE_H_
#define _TRAFFICLIGHT_PTRAFFICLIGHTINTERFACE_H_

#include "etDatatypes.h"
#include "modelbase/etPort.h"


/* include all referenced room classes */


/* message IDs */
enum PTrafficLightInterface_msg_ids {
	PTrafficLightInterface_MSG_MIN = 0,
	PTrafficLightInterface_OUT_connected = 1,
	PTrafficLightInterface_OUT_pressedRequestButton = 2,
	PTrafficLightInterface_IN_connect = 3,
	PTrafficLightInterface_IN_setCarRed = 4,
	PTrafficLightInterface_IN_setCarYellow = 5,
	PTrafficLightInterface_IN_setCarGreen = 6,
	PTrafficLightInterface_IN_setPedRed = 7,
	PTrafficLightInterface_IN_setPedGreen = 8,
	PTrafficLightInterface_IN_setRequestButtonActive = 9,
	PTrafficLightInterface_MSG_MAX = 10
};

/*--------------------- port structs and methods */
typedef etPort PTrafficLightInterfacePort;
typedef etReplPort PTrafficLightInterfaceReplPort;


void PTrafficLightInterfacePort_connected(const PTrafficLightInterfacePort* self);
void PTrafficLightInterfaceReplPort_connected_broadcast(const PTrafficLightInterfaceReplPort* self);
void PTrafficLightInterfaceReplPort_connected(const PTrafficLightInterfaceReplPort* self, int idx);
void PTrafficLightInterfacePort_pressedRequestButton(const PTrafficLightInterfacePort* self);
void PTrafficLightInterfaceReplPort_pressedRequestButton_broadcast(const PTrafficLightInterfaceReplPort* self);
void PTrafficLightInterfaceReplPort_pressedRequestButton(const PTrafficLightInterfaceReplPort* self, int idx);


etInt32 PTrafficLightInterfaceReplPort_getReplication(const PTrafficLightInterfaceReplPort* self);
typedef etPort PTrafficLightInterfaceConjPort;
typedef etReplPort PTrafficLightInterfaceConjReplPort;


void PTrafficLightInterfaceConjPort_connect(const PTrafficLightInterfaceConjPort* self, int32 data);
void PTrafficLightInterfaceConjReplPort_connect_broadcast(const PTrafficLightInterfaceConjReplPort* self, int32 data);
void PTrafficLightInterfaceConjReplPort_connect(const PTrafficLightInterfaceConjReplPort* self, int idx, int32 data);
void PTrafficLightInterfaceConjPort_setCarRed(const PTrafficLightInterfaceConjPort* self, bool data);
void PTrafficLightInterfaceConjReplPort_setCarRed_broadcast(const PTrafficLightInterfaceConjReplPort* self, bool data);
void PTrafficLightInterfaceConjReplPort_setCarRed(const PTrafficLightInterfaceConjReplPort* self, int idx, bool data);
void PTrafficLightInterfaceConjPort_setCarYellow(const PTrafficLightInterfaceConjPort* self, bool data);
void PTrafficLightInterfaceConjReplPort_setCarYellow_broadcast(const PTrafficLightInterfaceConjReplPort* self, bool data);
void PTrafficLightInterfaceConjReplPort_setCarYellow(const PTrafficLightInterfaceConjReplPort* self, int idx, bool data);
void PTrafficLightInterfaceConjPort_setCarGreen(const PTrafficLightInterfaceConjPort* self, bool data);
void PTrafficLightInterfaceConjReplPort_setCarGreen_broadcast(const PTrafficLightInterfaceConjReplPort* self, bool data);
void PTrafficLightInterfaceConjReplPort_setCarGreen(const PTrafficLightInterfaceConjReplPort* self, int idx, bool data);
void PTrafficLightInterfaceConjPort_setPedRed(const PTrafficLightInterfaceConjPort* self, bool data);
void PTrafficLightInterfaceConjReplPort_setPedRed_broadcast(const PTrafficLightInterfaceConjReplPort* self, bool data);
void PTrafficLightInterfaceConjReplPort_setPedRed(const PTrafficLightInterfaceConjReplPort* self, int idx, bool data);
void PTrafficLightInterfaceConjPort_setPedGreen(const PTrafficLightInterfaceConjPort* self, bool data);
void PTrafficLightInterfaceConjReplPort_setPedGreen_broadcast(const PTrafficLightInterfaceConjReplPort* self, bool data);
void PTrafficLightInterfaceConjReplPort_setPedGreen(const PTrafficLightInterfaceConjReplPort* self, int idx, bool data);
void PTrafficLightInterfaceConjPort_setRequestButtonActive(const PTrafficLightInterfaceConjPort* self, bool data);
void PTrafficLightInterfaceConjReplPort_setRequestButtonActive_broadcast(const PTrafficLightInterfaceConjReplPort* self, bool data);
void PTrafficLightInterfaceConjReplPort_setRequestButtonActive(const PTrafficLightInterfaceConjReplPort* self, int idx, bool data);


etInt32 PTrafficLightInterfaceConjReplPort_getReplication(const PTrafficLightInterfaceConjReplPort* self);

/*--------------------- debug helpers */

/* get message string for message id */
const char* PTrafficLightInterface_getMessageString(int msg_id);


#endif /* _TRAFFICLIGHT_PTRAFFICLIGHTINTERFACE_H_ */

