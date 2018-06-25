/**
 * @author generated by eTrice
 *
 * Header File of ActorClass PedestrianTrafficLightController
 *
 */

#ifndef _TRAFFICLIGHT_PEDESTRIANTRAFFICLIGHTCONTROLLER_H_
#define _TRAFFICLIGHT_PEDESTRIANTRAFFICLIGHTCONTROLLER_H_

#include "etDatatypes.h"
#include "messaging/etMessage.h"

/* include all referenced room classes */
#include "room/basic/service/timing/PTimer.h"
#include "TrafficLight/PTrafficLightController.h"
#include "TrafficLight/PTrafficLightInterface.h"


typedef struct PedestrianTrafficLightController PedestrianTrafficLightController;

/* const part of ActorClass (ROM) */
typedef struct PedestrianTrafficLightController_const {
	const char* instName;

	/* simple ports */
	const PTrafficLightControllerPort fct;
	const PTrafficLightInterfaceConjPort tlInterface;

	/* data receive ports */

	/* saps */
	const PTimerConjPort to;

	/* replicated ports */

	/* services */
} PedestrianTrafficLightController_const;


/* constant for state machine data */
#define PEDESTRIANTRAFFICLIGHTCONTROLLER_HISTORY_SIZE 4

/* variable part of ActorClass (RAM) */
struct PedestrianTrafficLightController {
	const PedestrianTrafficLightController_const* const constData;

	/* data send ports */

	/*--------------------- attributes ---------------------*/
	 int32 timeBase;


	/* state machine variables */
	etInt16 state;
	etInt16 history[PEDESTRIANTRAFFICLIGHTCONTROLLER_HISTORY_SIZE];
};

void PedestrianTrafficLightController_init(PedestrianTrafficLightController* self);

void PedestrianTrafficLightController_receiveMessage(void* self, const void* ifitem, const etMessage* msg);


/*--------------------- user constructor/destructor ---------------------*/

/*--------------------- operations ---------------------*/


#endif /* _TRAFFICLIGHT_PEDESTRIANTRAFFICLIGHTCONTROLLER_H_ */

