/**
 * @author generated by eTrice
 *
 * Source File of ActorClass ADAS_Controller
 *
 */

#include "ADAS_Controller.h"

#include "modelbase/etActor.h"
#include "debugging/etLogger.h"
#include "debugging/etMSCLogger.h"
#include "etUnit/etUnit.h"
#include "base/etMemory.h"

#include "TemplateModel/PSendData.h"

#include "ADAS_Controller_Utils.h"


/* interface item IDs */
enum interface_items {
	IFITEM_dataPortB = 1,
	IFITEM_relayPortA = 2,
	IFITEM_relayPortB = 3,
	IFITEM_relayPortC = 4
};

/* state IDs */
enum state_ids {
	NO_STATE = 0,
	STATE_TOP = 1,
	STATE_waitingData = 2,
	STATE_EmergencyStop = 3,
	STATE_NormalStop = 4,
	STATE_LaneChange = 5,
	STATE_Go = 6,
	STATE_MAX = 7
};

/* transition chains */
enum ChainIDs {
	CHAIN_TRANS_INITIAL_TO__waitingData = 1,
	CHAIN_TRANS_tr0_FROM_waitingData_TO_cp0_BY_sendDatadataPortB = 2,
	CHAIN_TRANS_tr5_FROM_NormalStop_TO_waitingData_BY_receivedDatarelayPortA = 3,
	CHAIN_TRANS_tr6_FROM_Go_TO_waitingData_BY_receivedDatarelayPortA = 4,
	CHAIN_TRANS_tr7_FROM_EmergencyStop_TO_waitingData_BY_receivedDatarelayPortC = 5,
	CHAIN_TRANS_tr8_FROM_LaneChange_TO_waitingData_BY_receivedDatarelayPortB = 6
};

/* triggers */
enum triggers {
	POLLING = 0,
	TRIG_dataPortB__sendData = IFITEM_dataPortB + EVT_SHIFT*PSendData_IN_sendData,
	TRIG_dataPortB__forRingControl = IFITEM_dataPortB + EVT_SHIFT*PSendData_IN_forRingControl,
	TRIG_relayPortA__receivedData = IFITEM_relayPortA + EVT_SHIFT*PSendData_OUT_receivedData,
	TRIG_relayPortB__receivedData = IFITEM_relayPortB + EVT_SHIFT*PSendData_OUT_receivedData,
	TRIG_relayPortC__receivedData = IFITEM_relayPortC + EVT_SHIFT*PSendData_OUT_receivedData
};

/* state names */
static char* stateStrings[] = {"<no state>","<top>","waitingData",
"EmergencyStop",
"NormalStop",
"LaneChange",
"Go"
};

static void setState(ADAS_Controller* self, etInt16 new_state) {
	self->state = new_state;
	ET_MSC_LOGGER_CHANGE_STATE(self->constData->instName, stateStrings[new_state])
}

static etInt16 getState(ADAS_Controller* self) {
	return self->state;
}

/* Entry and Exit Codes */
static void entry_EmergencyStop(ADAS_Controller* self) {
	ACC();
	ALK();
	AEB();
}
static void entry_NormalStop(ADAS_Controller* self) {
	ACC();
	ALK();
	AEB();
}
static void entry_LaneChange(ADAS_Controller* self) {
	ACC();
	ALK();
	AEB();
}
static void entry_Go(ADAS_Controller* self) {
	ACC();
	ALK();
	AEB();
}

/* Action Codes */
static void action_TRANS_tr0_FROM_waitingData_TO_cp0_BY_sendDatadataPortB(ADAS_Controller* self, const InterfaceItemBase* ifitem, DDataBuffer* data) {
    strcpy(str, data->buffer);
    strcpy(retain_str, str);
    
    temp_string = strtok(str, ",");
    velocity = (200*atof(temp_string))/200;
    
    temp_string = strtok(NULL, ",");
    distance = atof(temp_string);
    
    temp_string = strtok(NULL, ",");
    colliderNum = atoi(temp_string);
    
    temp_string = strtok(NULL, ",");
    steering = atof(temp_string);
    
    temp_string = strtok(NULL, ",");
    trafficLight = atof(temp_string);
    
    //temp_string = strtok(NULL, ", ");
    //something for decide LaneChange situation
}
static void action_TRANS_tr1_FROM_cp0_TO_NormalStop_COND_tr1(ADAS_Controller* self, const InterfaceItemBase* ifitem, DDataBuffer* data) {
    strcpy(retain_str, strcat(retain_str, ",N"));
}
static void action_TRANS_tr2_FROM_cp0_TO_LaneChange_COND_tr2(ADAS_Controller* self, const InterfaceItemBase* ifitem, DDataBuffer* data) {
    strcpy(retain_str, strcat(retain_str, ",L"));
}
static void action_TRANS_tr3_FROM_cp0_TO_Go(ADAS_Controller* self, const InterfaceItemBase* ifitem, DDataBuffer* data) {
    strcpy(retain_str, strcat(retain_str, ",G"));
}
static void action_TRANS_tr4_FROM_cp0_TO_EmergencyStop_COND_tr4(ADAS_Controller* self, const InterfaceItemBase* ifitem, DDataBuffer* data) {
    strcpy(retain_str, strcat(retain_str, ",E"));
}
static void action_TRANS_tr5_FROM_NormalStop_TO_waitingData_BY_receivedDatarelayPortA(ADAS_Controller* self, const InterfaceItemBase* ifitem, DDataBuffer* data) {
    strcpy(str, data->buffer);
    strcpy(send_str, str);
    DDataBuffer buf;
    strcpy(buf.buffer, send_str);
    dataPortB_receivedData(&buf);
}
static void action_TRANS_tr6_FROM_Go_TO_waitingData_BY_receivedDatarelayPortA(ADAS_Controller* self, const InterfaceItemBase* ifitem, DDataBuffer* data) {
    strcpy(str, data->buffer);
    strcpy(send_str, str);
    DDataBuffer buf;
    strcpy(buf.buffer, send_str);
    dataPortB_receivedData(&buf);
}
static void action_TRANS_tr7_FROM_EmergencyStop_TO_waitingData_BY_receivedDatarelayPortC(ADAS_Controller* self, const InterfaceItemBase* ifitem, DDataBuffer* data) {
    strcpy(str, data->buffer);
    strcpy(send_str, str);
    DDataBuffer buf;
    strcpy(buf.buffer, send_str);
    dataPortB_receivedData(&buf);
}
static void action_TRANS_tr8_FROM_LaneChange_TO_waitingData_BY_receivedDatarelayPortB(ADAS_Controller* self, const InterfaceItemBase* ifitem, DDataBuffer* data) {
    strcpy(str, data->buffer);
    strcpy(send_str, str);
    DDataBuffer buf;
    strcpy(buf.buffer, send_str);
    dataPortB_receivedData(&buf);
}

/* State Switch Methods */
/**
 * calls exit codes while exiting from the current state to one of its
 * parent states while remembering the history
 * @param current__et - the current state
 * @param to - the final parent state
 */
static void exitTo(ADAS_Controller* self, etInt16 current__et, etInt16 to) {
	while (current__et!=to) {
		switch (current__et) {
			case STATE_waitingData:
				self->history[STATE_TOP] = STATE_waitingData;
				current__et = STATE_TOP;
				break;
			case STATE_EmergencyStop:
				self->history[STATE_TOP] = STATE_EmergencyStop;
				current__et = STATE_TOP;
				break;
			case STATE_NormalStop:
				self->history[STATE_TOP] = STATE_NormalStop;
				current__et = STATE_TOP;
				break;
			case STATE_LaneChange:
				self->history[STATE_TOP] = STATE_LaneChange;
				current__et = STATE_TOP;
				break;
			case STATE_Go:
				self->history[STATE_TOP] = STATE_Go;
				current__et = STATE_TOP;
				break;
			default:
				/* should not occur */
				break;
		}
	}
}

/**
 * calls action, entry and exit codes along a transition chain. The generic data are cast to typed data
 * matching the trigger of this chain. The ID of the final state is returned
 * @param chain__et - the chain ID
 * @param generic_data__et - the generic data pointer
 * @return the +/- ID of the final state either with a positive sign, that indicates to execute the state's entry code, or a negative sign vice versa
 */
static etInt16 executeTransitionChain(ADAS_Controller* self, int chain__et, const InterfaceItemBase* ifitem, void* generic_data__et) {
	switch (chain__et) {
		case CHAIN_TRANS_INITIAL_TO__waitingData:
		{
			return STATE_waitingData;
		}
		case CHAIN_TRANS_tr0_FROM_waitingData_TO_cp0_BY_sendDatadataPortB:
		{
			DDataBuffer* data = ((DDataBuffer*) generic_data__et);
			action_TRANS_tr0_FROM_waitingData_TO_cp0_BY_sendDatadataPortB(self, ifitem, data);
			if (ChoicePoint0(distance, velocity, trafficLight, colliderNum) == 2) {
			action_TRANS_tr1_FROM_cp0_TO_NormalStop_COND_tr1(self, ifitem, data);
			return STATE_NormalStop;}
			else if (ChoicePoint0(distance, velocity, trafficLight, colliderNum) == 3) {
			action_TRANS_tr2_FROM_cp0_TO_LaneChange_COND_tr2(self, ifitem, data);
			return STATE_LaneChange;}
			else if (ChoicePoint0(distance, velocity, trafficLight, colliderNum) == 1) {
			action_TRANS_tr4_FROM_cp0_TO_EmergencyStop_COND_tr4(self, ifitem, data);
			return STATE_EmergencyStop;}
			else {
			action_TRANS_tr3_FROM_cp0_TO_Go(self, ifitem, data);
			return STATE_Go;}
		}
		case CHAIN_TRANS_tr5_FROM_NormalStop_TO_waitingData_BY_receivedDatarelayPortA:
		{
			DDataBuffer* data = ((DDataBuffer*) generic_data__et);
			action_TRANS_tr5_FROM_NormalStop_TO_waitingData_BY_receivedDatarelayPortA(self, ifitem, data);
			return STATE_waitingData;
		}
		case CHAIN_TRANS_tr6_FROM_Go_TO_waitingData_BY_receivedDatarelayPortA:
		{
			DDataBuffer* data = ((DDataBuffer*) generic_data__et);
			action_TRANS_tr6_FROM_Go_TO_waitingData_BY_receivedDatarelayPortA(self, ifitem, data);
			return STATE_waitingData;
		}
		case CHAIN_TRANS_tr7_FROM_EmergencyStop_TO_waitingData_BY_receivedDatarelayPortC:
		{
			DDataBuffer* data = ((DDataBuffer*) generic_data__et);
			action_TRANS_tr7_FROM_EmergencyStop_TO_waitingData_BY_receivedDatarelayPortC(self, ifitem, data);
			return STATE_waitingData;
		}
		case CHAIN_TRANS_tr8_FROM_LaneChange_TO_waitingData_BY_receivedDatarelayPortB:
		{
			DDataBuffer* data = ((DDataBuffer*) generic_data__et);
			action_TRANS_tr8_FROM_LaneChange_TO_waitingData_BY_receivedDatarelayPortB(self, ifitem, data);
			return STATE_waitingData;
		}
			default:
				/* should not occur */
				break;
	}
	return NO_STATE;
}

/**
 * calls entry codes while entering a state's history. The ID of the final leaf state is returned
 * @param state__et - the state which is entered
 * @return - the ID of the final leaf state
 */
static etInt16 enterHistory(ADAS_Controller* self, etInt16 state__et) {
	etBool skip_entry__et = ET_FALSE;
	if (state__et >= STATE_MAX) {
		state__et = (etInt16) (state__et - STATE_MAX);
		skip_entry__et = ET_TRUE;
	}
	while (ET_TRUE) {
		switch (state__et) {
			case STATE_waitingData:
				/* in leaf state: return state id */
				return STATE_waitingData;
			case STATE_EmergencyStop:
				if (!(skip_entry__et)) entry_EmergencyStop(self);
				/* in leaf state: return state id */
				return STATE_EmergencyStop;
			case STATE_NormalStop:
				if (!(skip_entry__et)) entry_NormalStop(self);
				/* in leaf state: return state id */
				return STATE_NormalStop;
			case STATE_LaneChange:
				if (!(skip_entry__et)) entry_LaneChange(self);
				/* in leaf state: return state id */
				return STATE_LaneChange;
			case STATE_Go:
				if (!(skip_entry__et)) entry_Go(self);
				/* in leaf state: return state id */
				return STATE_Go;
			case STATE_TOP:
				state__et = self->history[STATE_TOP];
				break;
			default:
				/* should not occur */
				break;
		}
		skip_entry__et = ET_FALSE;
	}
	/* return NO_STATE; // required by CDT but detected as unreachable by JDT because of while (true) */
}

static void ADAS_Controller_executeInitTransition(ADAS_Controller* self) {
	int chain__et = CHAIN_TRANS_INITIAL_TO__waitingData;
	etInt16 next__et = executeTransitionChain(self, chain__et, NULL, NULL);
	next__et = enterHistory(self, next__et);
	setState(self, next__et);
}

/* receiveEvent contains the main implementation of the FSM */
static void ADAS_Controller_receiveEventInternal(ADAS_Controller* self, InterfaceItemBase* ifitem, int localId, int evt, void* generic_data__et) {
	int trigger__et = localId + EVT_SHIFT*evt;
	int chain__et = NOT_CAUGHT;
	etInt16 catching_state__et = NO_STATE;
	((void)trigger__et);	/* avoids unused warning */

	if (!handleSystemEvent(ifitem, evt, generic_data__et)) {
		switch (getState(self)) {
		    case STATE_waitingData:
		        switch(trigger__et) {
		                case TRIG_dataPortB__sendData:
		                    {
		                        chain__et = CHAIN_TRANS_tr0_FROM_waitingData_TO_cp0_BY_sendDatadataPortB;
		                        catching_state__et = STATE_TOP;
		                    }
		                break;
		                default:
		                    /* should not occur */
		                    break;
		        }
		        break;
		    case STATE_EmergencyStop:
		        switch(trigger__et) {
		                case TRIG_relayPortC__receivedData:
		                    {
		                        chain__et = CHAIN_TRANS_tr7_FROM_EmergencyStop_TO_waitingData_BY_receivedDatarelayPortC;
		                        catching_state__et = STATE_TOP;
		                    }
		                break;
		                default:
		                    /* should not occur */
		                    break;
		        }
		        break;
		    case STATE_NormalStop:
		        switch(trigger__et) {
		                case TRIG_relayPortA__receivedData:
		                    {
		                        chain__et = CHAIN_TRANS_tr5_FROM_NormalStop_TO_waitingData_BY_receivedDatarelayPortA;
		                        catching_state__et = STATE_TOP;
		                    }
		                break;
		                default:
		                    /* should not occur */
		                    break;
		        }
		        break;
		    case STATE_LaneChange:
		        switch(trigger__et) {
		                case TRIG_relayPortB__receivedData:
		                    {
		                        chain__et = CHAIN_TRANS_tr8_FROM_LaneChange_TO_waitingData_BY_receivedDatarelayPortB;
		                        catching_state__et = STATE_TOP;
		                    }
		                break;
		                default:
		                    /* should not occur */
		                    break;
		        }
		        break;
		    case STATE_Go:
		        switch(trigger__et) {
		                case TRIG_relayPortA__receivedData:
		                    {
		                        chain__et = CHAIN_TRANS_tr6_FROM_Go_TO_waitingData_BY_receivedDatarelayPortA;
		                        catching_state__et = STATE_TOP;
		                    }
		                break;
		                default:
		                    /* should not occur */
		                    break;
		        }
		        break;
		    default:
		        /* should not occur */
		        break;
		}
	}
	if (chain__et != NOT_CAUGHT) {
		exitTo(self, getState(self), catching_state__et);
		{
			etInt16 next__et = executeTransitionChain(self, chain__et, ifitem, generic_data__et);
			next__et = enterHistory(self, next__et);
			setState(self, next__et);
		}
	}
}
static void ADAS_Controller_receiveEvent(ADAS_Controller* self, InterfaceItemBase* ifitem, int evt, void* generic_data__et) {
	int localId = (ifitem==NULL)? 0 : ifitem->localId;
	ADAS_Controller_receiveEventInternal(self, ifitem, localId, evt, generic_data__et);
}

void ADAS_Controller_init(ADAS_Controller* self){
	ET_MSC_LOGGER_SYNC_ENTRY("ADAS_Controller", "init")
	self->state = STATE_TOP;
	{
		int i;
		for (i=0; i<ADAS_CONTROLLER_HISTORY_SIZE; ++i)
			self->history[i] = NO_STATE;
	}
	ADAS_Controller_executeInitTransition(self);
	ET_MSC_LOGGER_SYNC_EXIT
}


void ADAS_Controller_receiveMessage(void* self, const void* ifitem, const etMessage* msg){
	ET_MSC_LOGGER_SYNC_ENTRY("ADAS_Controller", "_receiveMessage")
	ADAS_Controller_receiveEvent(self, (etPort*)ifitem, msg->evtID, (void*)(((char*)msg)+MEM_CEIL(sizeof(etMessage))));

	ET_MSC_LOGGER_SYNC_EXIT
}


/*--------------------- user constructor/destructor ---------------------*/

/*--------------------- operations ---------------------*/
 void ADAS_Controller_ALK(ADAS_Controller* self) {
	DDataBuffer buf;
	strcpy(buf.buffer, retain_str);
	relayPortB_sendData(&buf);
	relayPortB_forRingControl();
}
 void ADAS_Controller_ACC(ADAS_Controller* self) {
	DDataBuffer buf;
	strcpy(buf.buffer, retain_str);
	relayPortA_sendData(&buf);
	relayPortA_forRingControl();
}
 int32 ADAS_Controller_ChoicePoint0(ADAS_Controller* self, float32 dist, float32 velo, float32 tl, int32 cnum) {
	if(cnum == 1){
		 if(dist < 18.0 && velo == 0.0)
			 return 3;
		 else if(dist <= 210 || velo >= 60)
			 return 2;
		 else
			 return 4;
	}
	else if(cnum == 2){
		 if(dist < 10.0 && velo == 0.0)
			 return 3;
		 else if(dist <= 10)
			 return 1;
		 else if(velo >= 60)
			 return 2;
		 else
			 return 4;
	}
	else{
		 if(dist <= 10 && tl > 0)
			 return 1;
		 else if((dist <= 130 && tl > 0) || velo >= 60)
			 return 2;
		 else
			 return 4;
	}
}
 void ADAS_Controller_AEB(ADAS_Controller* self) {
	DDataBuffer buf;
	strcpy(buf.buffer, retain_str);
	relayPortC_sendData(&buf);
	relayPortC_forRingControl();
}
