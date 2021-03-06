/**
 * @author generated by eTrice
 *
 * Source File of ActorClass TestApplication
 *
 */

#include "TestApplication.h"

#include "modelbase/etActor.h"
#include "debugging/etLogger.h"
#include "debugging/etMSCLogger.h"
#include "etUnit/etUnit.h"
#include "base/etMemory.h"

#include "room/basic/service/timing/PTimer.h"
#include "TrafficLight/PTrafficLightController.h"
#include "TrafficLight/PTrafficLightInterface.h"

#include "TestApplication_Utils.h"


/* interface item IDs */
/* empty enum not generated */


void TestApplication_init(TestApplication* self){
	ET_MSC_LOGGER_SYNC_ENTRY("TestApplication", "init")
	ET_MSC_LOGGER_SYNC_EXIT
}


void TestApplication_receiveMessage(void* self, const void* ifitem, const etMessage* msg){
	ET_MSC_LOGGER_SYNC_ENTRY("TestApplication", "_receiveMessage")

	ET_MSC_LOGGER_SYNC_EXIT
}


/*--------------------- user constructor/destructor ---------------------*/

/*--------------------- operations ---------------------*/

