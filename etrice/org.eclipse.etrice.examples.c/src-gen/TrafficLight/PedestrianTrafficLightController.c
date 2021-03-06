/**
 * @author generated by eTrice
 *
 * Source File of ActorClass PedestrianTrafficLightController
 *
 */

#include "PedestrianTrafficLightController.h"

#include "modelbase/etActor.h"
#include "debugging/etLogger.h"
#include "debugging/etMSCLogger.h"
#include "etUnit/etUnit.h"
#include "base/etMemory.h"

#include "room/basic/service/timing/PTimer.h"
#include "TrafficLight/PTrafficLightController.h"
#include "TrafficLight/PTrafficLightInterface.h"

#include "PedestrianTrafficLightController_Utils.h"


/* interface item IDs */
enum interface_items {
	IFITEM_fct = 1,
	IFITEM_tlInterface = 2,
	IFITEM_to = 3
};

/* state IDs */
enum state_ids {
	NO_STATE = 0,
	STATE_TOP = 1,
	STATE_Standby = 2,
	STATE_Running = 3,
	STATE_Stopped = 4,
	STATE_Standby_On = 5,
	STATE_Standby_Off = 6,
	STATE_Running_AllRed = 7,
	STATE_Running_CarYellow = 8,
	STATE_Running_CarGreen = 9,
	STATE_Running_CarRed = 10,
	STATE_Running_PedGreen = 11,
	STATE_Running_CarYellowBeforeStandby = 12,
	STATE_Running_CarRedYellow = 13,
	STATE_AllRedBeforeStandby = 14,
	STATE_Connecting = 15,
	STATE_MAX = 16
};

/* transition chains */
enum ChainIDs {
	CHAIN_TRANS_INITIAL_TO__Stopped = 1,
	CHAIN_TRANS_tr0_FROM_Stopped_TO_Connecting_BY_standbyfct = 2,
	CHAIN_TRANS_tr1_FROM_Standby_TO_Running_tpStart_BY_startfct = 3,
	CHAIN_TRANS_tr2_FROM_Running_TO_AllRedBeforeStandby_BY_standbyfct = 4,
	CHAIN_TRANS_tr4_FROM_AllRedBeforeStandby_TO_Standby_tp0_BY_timeoutto = 5,
	CHAIN_TRANS_tr5_FROM_Standby_TO_Stopped_BY_stopfct = 6,
	CHAIN_TRANS_tr6_FROM_Connecting_TO_Standby_tp0_BY_connectedtlInterface = 7,
	CHAIN_Standby_TRANS_tr1_FROM_On_TO_Off_BY_timeoutto = 8,
	CHAIN_Standby_TRANS_tr2_FROM_Off_TO_On_BY_timeoutto = 9,
	CHAIN_Running_TRANS_tr1_FROM_AllRed_TO_CarRedYellow_BY_timeoutto = 10,
	CHAIN_Running_TRANS_tr2_FROM_CarGreen_TO_CarYellow_BY_pressedRequestButtontlInterface = 11,
	CHAIN_Running_TRANS_tr3_FROM_CarYellow_TO_CarRed_BY_timeoutto = 12,
	CHAIN_Running_TRANS_tr4_FROM_CarRed_TO_PedGreen_BY_timeoutto = 13,
	CHAIN_Running_TRANS_tr5_FROM_PedGreen_TO_AllRed_BY_timeoutto = 14,
	CHAIN_Running_TRANS_tr6_FROM_CarGreen_TO_CarYellowBeforeStandby_BY_standbyfct = 15,
	CHAIN_Running_TRANS_tr7_FROM_CarYellowBeforeStandby_TO_tpStandby_BY_timeoutto = 16,
	CHAIN_Running_TRANS_tr8_FROM_CarRedYellow_TO_CarGreen_BY_timeoutto = 17
};

/* triggers */
enum triggers {
	POLLING = 0,
	TRIG_fct__standby = IFITEM_fct + EVT_SHIFT*PTrafficLightController_IN_standby,
	TRIG_fct__start = IFITEM_fct + EVT_SHIFT*PTrafficLightController_IN_start,
	TRIG_fct__stop = IFITEM_fct + EVT_SHIFT*PTrafficLightController_IN_stop,
	TRIG_tlInterface__connected = IFITEM_tlInterface + EVT_SHIFT*PTrafficLightInterface_OUT_connected,
	TRIG_tlInterface__pressedRequestButton = IFITEM_tlInterface + EVT_SHIFT*PTrafficLightInterface_OUT_pressedRequestButton,
	TRIG_to__timeout = IFITEM_to + EVT_SHIFT*PTimer_OUT_timeout
};

/* state names */
static char* stateStrings[] = {"<no state>","<top>","Standby",
"Running",
"Stopped",
"Standby_On",
"Standby_Off",
"Running_AllRed",
"Running_CarYellow",
"Running_CarGreen",
"Running_CarRed",
"Running_PedGreen",
"Running_CarYellowBeforeStandby",
"Running_CarRedYellow",
"AllRedBeforeStandby",
"Connecting"
};

static void setState(PedestrianTrafficLightController* self, etInt16 new_state) {
	self->state = new_state;
	ET_MSC_LOGGER_CHANGE_STATE(self->constData->instName, stateStrings[new_state])
}

static etInt16 getState(PedestrianTrafficLightController* self) {
	return self->state;
}

/* Entry and Exit Codes */
static void entry_Stopped(PedestrianTrafficLightController* self) {
	tlInterface_setCarRed(0);
	tlInterface_setCarYellow(0);
	tlInterface_setCarGreen(0);
	tlInterface_setPedRed(0);
	tlInterface_setPedGreen(0);
	fct_doneStop();
}
static void entry_Standby(PedestrianTrafficLightController* self) {
	fct_doneStandby();
}
static void entry_Standby_On(PedestrianTrafficLightController* self) {
	// turn two lights on
	tlInterface_setCarYellow(1);
	tlInterface_setPedRed(1);
	
	// start timeout (fire once) for blinking
	// startTimer would start a cyclic timer
	to_startTimeout(5*timeBase);
}
static void exit_Standby_On(PedestrianTrafficLightController* self) {
	// TIP: turn off lights here in the exit code of state On instead of the entry code of state Off 
	// to make sure they are turned off if the superstate Standby is left by a group transition
	tlInterface_setCarYellow(0);
	tlInterface_setPedRed(0);
	
	// TIP: kill timer here to make sure it is killed if the state is left by a group transition or any other transition than a timeout
	// ALTERNATIVE: kill() could also be placed in the exit code of the superstate StandbyBlinking and so replacing the two calls in On:exit and Off:exit
	to_kill();
}
static void entry_Standby_Off(PedestrianTrafficLightController* self) {
	to_startTimeout(5*timeBase);
}
static void exit_Standby_Off(PedestrianTrafficLightController* self) {
	to_kill();
}
static void entry_Running(PedestrianTrafficLightController* self) {
	fct_doneStart();
}
static void exit_Running(PedestrianTrafficLightController* self) {
	to_kill();
}
static void entry_Running_AllRed(PedestrianTrafficLightController* self) {
	tlInterface_setCarRed(1);
	tlInterface_setPedRed(1);
	tlInterface_setPedGreen(0);
	
	to_startTimeout(10*timeBase);
}
static void entry_Running_CarYellow(PedestrianTrafficLightController* self) {
	tlInterface_setCarGreen(0);
	tlInterface_setCarYellow(1);
	to_startTimeout(10*timeBase);
}
static void entry_Running_CarGreen(PedestrianTrafficLightController* self) {
	tlInterface_setCarRed(0);
	tlInterface_setCarYellow(0);
	tlInterface_setCarGreen(1);
}
static void entry_Running_CarRed(PedestrianTrafficLightController* self) {
	tlInterface_setCarYellow(0);
	tlInterface_setCarRed(1);
	to_startTimeout(10*timeBase);
}
static void entry_Running_PedGreen(PedestrianTrafficLightController* self) {
	tlInterface_setPedRed(0);
	tlInterface_setPedGreen(1);
	to_startTimeout(20*timeBase);
}
static void entry_Running_CarYellowBeforeStandby(PedestrianTrafficLightController* self) {
	tlInterface_setCarGreen(0);
	tlInterface_setCarYellow(1);
	to_startTimeout(10*timeBase);
}
static void entry_Running_CarRedYellow(PedestrianTrafficLightController* self) {
	tlInterface_setCarYellow(1);
	to_startTimeout(10*timeBase);
}
static void entry_AllRedBeforeStandby(PedestrianTrafficLightController* self) {
	tlInterface_setCarRed(1);
	tlInterface_setPedRed(1);
	to_startTimeout(30*timeBase);
}

/* Action Codes */
static void action_TRANS_INITIAL_TO__Stopped(PedestrianTrafficLightController* self) {
    timeBase = 100;
}
static void action_TRANS_tr0_FROM_Stopped_TO_Connecting_BY_standbyfct(PedestrianTrafficLightController* self, const InterfaceItemBase* ifitem, int32 port) {
    printf("ptlc: connecting to port %d\n", (int)port);
    tlInterface_connect(port);
}

/* State Switch Methods */
/**
 * calls exit codes while exiting from the current state to one of its
 * parent states while remembering the history
 * @param current__et - the current state
 * @param to - the final parent state
 */
static void exitTo(PedestrianTrafficLightController* self, etInt16 current__et, etInt16 to) {
	while (current__et!=to) {
		switch (current__et) {
			case STATE_Stopped:
				self->history[STATE_TOP] = STATE_Stopped;
				current__et = STATE_TOP;
				break;
			case STATE_Standby:
				self->history[STATE_TOP] = STATE_Standby;
				current__et = STATE_TOP;
				break;
			case STATE_Standby_On:
				exit_Standby_On(self);
				self->history[STATE_Standby] = STATE_Standby_On;
				current__et = STATE_Standby;
				break;
			case STATE_Standby_Off:
				exit_Standby_Off(self);
				self->history[STATE_Standby] = STATE_Standby_Off;
				current__et = STATE_Standby;
				break;
			case STATE_Running:
				exit_Running(self);
				self->history[STATE_TOP] = STATE_Running;
				current__et = STATE_TOP;
				break;
			case STATE_Running_AllRed:
				self->history[STATE_Running] = STATE_Running_AllRed;
				current__et = STATE_Running;
				break;
			case STATE_Running_CarYellow:
				self->history[STATE_Running] = STATE_Running_CarYellow;
				current__et = STATE_Running;
				break;
			case STATE_Running_CarGreen:
				self->history[STATE_Running] = STATE_Running_CarGreen;
				current__et = STATE_Running;
				break;
			case STATE_Running_CarRed:
				self->history[STATE_Running] = STATE_Running_CarRed;
				current__et = STATE_Running;
				break;
			case STATE_Running_PedGreen:
				self->history[STATE_Running] = STATE_Running_PedGreen;
				current__et = STATE_Running;
				break;
			case STATE_Running_CarYellowBeforeStandby:
				self->history[STATE_Running] = STATE_Running_CarYellowBeforeStandby;
				current__et = STATE_Running;
				break;
			case STATE_Running_CarRedYellow:
				self->history[STATE_Running] = STATE_Running_CarRedYellow;
				current__et = STATE_Running;
				break;
			case STATE_AllRedBeforeStandby:
				self->history[STATE_TOP] = STATE_AllRedBeforeStandby;
				current__et = STATE_TOP;
				break;
			case STATE_Connecting:
				self->history[STATE_TOP] = STATE_Connecting;
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
static etInt16 executeTransitionChain(PedestrianTrafficLightController* self, int chain__et, const InterfaceItemBase* ifitem, void* generic_data__et) {
	switch (chain__et) {
		case CHAIN_TRANS_INITIAL_TO__Stopped:
		{
			action_TRANS_INITIAL_TO__Stopped(self);
			return STATE_Stopped;
		}
		case CHAIN_TRANS_tr0_FROM_Stopped_TO_Connecting_BY_standbyfct:
		{
			int32 port = *((int32*) generic_data__et);
			action_TRANS_tr0_FROM_Stopped_TO_Connecting_BY_standbyfct(self, ifitem, port);
			return STATE_Connecting;
		}
		case CHAIN_TRANS_tr1_FROM_Standby_TO_Running_tpStart_BY_startfct:
		{
			entry_Running(self);
			return STATE_Running_AllRed;
		}
		case CHAIN_TRANS_tr2_FROM_Running_TO_AllRedBeforeStandby_BY_standbyfct:
		{
			int32 port = *((int32*) generic_data__et);
			return STATE_AllRedBeforeStandby;
		}
		case CHAIN_TRANS_tr4_FROM_AllRedBeforeStandby_TO_Standby_tp0_BY_timeoutto:
		{
			entry_Standby(self);
			return STATE_Standby_On;
		}
		case CHAIN_TRANS_tr5_FROM_Standby_TO_Stopped_BY_stopfct:
		{
			return STATE_Stopped;
		}
		case CHAIN_TRANS_tr6_FROM_Connecting_TO_Standby_tp0_BY_connectedtlInterface:
		{
			entry_Standby(self);
			return STATE_Standby_On;
		}
		case CHAIN_Standby_TRANS_tr1_FROM_On_TO_Off_BY_timeoutto:
		{
			return STATE_Standby_Off;
		}
		case CHAIN_Standby_TRANS_tr2_FROM_Off_TO_On_BY_timeoutto:
		{
			return STATE_Standby_On;
		}
		case CHAIN_Running_TRANS_tr1_FROM_AllRed_TO_CarRedYellow_BY_timeoutto:
		{
			return STATE_Running_CarRedYellow;
		}
		case CHAIN_Running_TRANS_tr2_FROM_CarGreen_TO_CarYellow_BY_pressedRequestButtontlInterface:
		{
			return STATE_Running_CarYellow;
		}
		case CHAIN_Running_TRANS_tr3_FROM_CarYellow_TO_CarRed_BY_timeoutto:
		{
			return STATE_Running_CarRed;
		}
		case CHAIN_Running_TRANS_tr4_FROM_CarRed_TO_PedGreen_BY_timeoutto:
		{
			return STATE_Running_PedGreen;
		}
		case CHAIN_Running_TRANS_tr5_FROM_PedGreen_TO_AllRed_BY_timeoutto:
		{
			return STATE_Running_AllRed;
		}
		case CHAIN_Running_TRANS_tr6_FROM_CarGreen_TO_CarYellowBeforeStandby_BY_standbyfct:
		{
			int32 port = *((int32*) generic_data__et);
			return STATE_Running_CarYellowBeforeStandby;
		}
		case CHAIN_Running_TRANS_tr7_FROM_CarYellowBeforeStandby_TO_tpStandby_BY_timeoutto:
		{
			exit_Running(self);
			return STATE_AllRedBeforeStandby;
		}
		case CHAIN_Running_TRANS_tr8_FROM_CarRedYellow_TO_CarGreen_BY_timeoutto:
		{
			return STATE_Running_CarGreen;
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
static etInt16 enterHistory(PedestrianTrafficLightController* self, etInt16 state__et) {
	etBool skip_entry__et = ET_FALSE;
	if (state__et >= STATE_MAX) {
		state__et = (etInt16) (state__et - STATE_MAX);
		skip_entry__et = ET_TRUE;
	}
	while (ET_TRUE) {
		switch (state__et) {
			case STATE_Stopped:
				if (!(skip_entry__et)) entry_Stopped(self);
				/* in leaf state: return state id */
				return STATE_Stopped;
			case STATE_Standby:
				if (!(skip_entry__et)) entry_Standby(self);
				/* state has a sub graph */
				/* without init transition */
				state__et = self->history[STATE_Standby];
				break;
			case STATE_Standby_On:
				if (!(skip_entry__et)) entry_Standby_On(self);
				/* in leaf state: return state id */
				return STATE_Standby_On;
			case STATE_Standby_Off:
				if (!(skip_entry__et)) entry_Standby_Off(self);
				/* in leaf state: return state id */
				return STATE_Standby_Off;
			case STATE_Running:
				if (!(skip_entry__et)) entry_Running(self);
				/* state has a sub graph */
				/* without init transition */
				state__et = self->history[STATE_Running];
				break;
			case STATE_Running_AllRed:
				if (!(skip_entry__et)) entry_Running_AllRed(self);
				/* in leaf state: return state id */
				return STATE_Running_AllRed;
			case STATE_Running_CarYellow:
				if (!(skip_entry__et)) entry_Running_CarYellow(self);
				/* in leaf state: return state id */
				return STATE_Running_CarYellow;
			case STATE_Running_CarGreen:
				if (!(skip_entry__et)) entry_Running_CarGreen(self);
				/* in leaf state: return state id */
				return STATE_Running_CarGreen;
			case STATE_Running_CarRed:
				if (!(skip_entry__et)) entry_Running_CarRed(self);
				/* in leaf state: return state id */
				return STATE_Running_CarRed;
			case STATE_Running_PedGreen:
				if (!(skip_entry__et)) entry_Running_PedGreen(self);
				/* in leaf state: return state id */
				return STATE_Running_PedGreen;
			case STATE_Running_CarYellowBeforeStandby:
				if (!(skip_entry__et)) entry_Running_CarYellowBeforeStandby(self);
				/* in leaf state: return state id */
				return STATE_Running_CarYellowBeforeStandby;
			case STATE_Running_CarRedYellow:
				if (!(skip_entry__et)) entry_Running_CarRedYellow(self);
				/* in leaf state: return state id */
				return STATE_Running_CarRedYellow;
			case STATE_AllRedBeforeStandby:
				if (!(skip_entry__et)) entry_AllRedBeforeStandby(self);
				/* in leaf state: return state id */
				return STATE_AllRedBeforeStandby;
			case STATE_Connecting:
				/* in leaf state: return state id */
				return STATE_Connecting;
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

static void PedestrianTrafficLightController_executeInitTransition(PedestrianTrafficLightController* self) {
	int chain__et = CHAIN_TRANS_INITIAL_TO__Stopped;
	etInt16 next__et = executeTransitionChain(self, chain__et, NULL, NULL);
	next__et = enterHistory(self, next__et);
	setState(self, next__et);
}

/* receiveEvent contains the main implementation of the FSM */
static void PedestrianTrafficLightController_receiveEventInternal(PedestrianTrafficLightController* self, InterfaceItemBase* ifitem, int localId, int evt, void* generic_data__et) {
	int trigger__et = localId + EVT_SHIFT*evt;
	int chain__et = NOT_CAUGHT;
	etInt16 catching_state__et = NO_STATE;
	((void)trigger__et);	/* avoids unused warning */

	if (!handleSystemEvent(ifitem, evt, generic_data__et)) {
		switch (getState(self)) {
		    case STATE_Stopped:
		        switch(trigger__et) {
		                case TRIG_fct__standby:
		                    {
		                        chain__et = CHAIN_TRANS_tr0_FROM_Stopped_TO_Connecting_BY_standbyfct;
		                        catching_state__et = STATE_TOP;
		                    }
		                break;
		                default:
		                    /* should not occur */
		                    break;
		        }
		        break;
		    case STATE_Standby_On:
		        switch(trigger__et) {
		                case TRIG_to__timeout:
		                    {
		                        chain__et = CHAIN_Standby_TRANS_tr1_FROM_On_TO_Off_BY_timeoutto;
		                        catching_state__et = STATE_Standby;
		                    }
		                break;
		                case TRIG_fct__start:
		                    {
		                        chain__et = CHAIN_TRANS_tr1_FROM_Standby_TO_Running_tpStart_BY_startfct;
		                        catching_state__et = STATE_TOP;
		                    }
		                break;
		                case TRIG_fct__stop:
		                    {
		                        chain__et = CHAIN_TRANS_tr5_FROM_Standby_TO_Stopped_BY_stopfct;
		                        catching_state__et = STATE_TOP;
		                    }
		                break;
		                default:
		                    /* should not occur */
		                    break;
		        }
		        break;
		    case STATE_Standby_Off:
		        switch(trigger__et) {
		                case TRIG_to__timeout:
		                    {
		                        chain__et = CHAIN_Standby_TRANS_tr2_FROM_Off_TO_On_BY_timeoutto;
		                        catching_state__et = STATE_Standby;
		                    }
		                break;
		                case TRIG_fct__start:
		                    {
		                        chain__et = CHAIN_TRANS_tr1_FROM_Standby_TO_Running_tpStart_BY_startfct;
		                        catching_state__et = STATE_TOP;
		                    }
		                break;
		                case TRIG_fct__stop:
		                    {
		                        chain__et = CHAIN_TRANS_tr5_FROM_Standby_TO_Stopped_BY_stopfct;
		                        catching_state__et = STATE_TOP;
		                    }
		                break;
		                default:
		                    /* should not occur */
		                    break;
		        }
		        break;
		    case STATE_Running_AllRed:
		        switch(trigger__et) {
		                case TRIG_to__timeout:
		                    {
		                        chain__et = CHAIN_Running_TRANS_tr1_FROM_AllRed_TO_CarRedYellow_BY_timeoutto;
		                        catching_state__et = STATE_Running;
		                    }
		                break;
		                case TRIG_fct__standby:
		                    {
		                        chain__et = CHAIN_TRANS_tr2_FROM_Running_TO_AllRedBeforeStandby_BY_standbyfct;
		                        catching_state__et = STATE_TOP;
		                    }
		                break;
		                default:
		                    /* should not occur */
		                    break;
		        }
		        break;
		    case STATE_Running_CarYellow:
		        switch(trigger__et) {
		                case TRIG_to__timeout:
		                    {
		                        chain__et = CHAIN_Running_TRANS_tr3_FROM_CarYellow_TO_CarRed_BY_timeoutto;
		                        catching_state__et = STATE_Running;
		                    }
		                break;
		                case TRIG_fct__standby:
		                    {
		                        chain__et = CHAIN_TRANS_tr2_FROM_Running_TO_AllRedBeforeStandby_BY_standbyfct;
		                        catching_state__et = STATE_TOP;
		                    }
		                break;
		                default:
		                    /* should not occur */
		                    break;
		        }
		        break;
		    case STATE_Running_CarGreen:
		        switch(trigger__et) {
		                case TRIG_tlInterface__pressedRequestButton:
		                    {
		                        chain__et = CHAIN_Running_TRANS_tr2_FROM_CarGreen_TO_CarYellow_BY_pressedRequestButtontlInterface;
		                        catching_state__et = STATE_Running;
		                    }
		                break;
		                case TRIG_fct__standby:
		                    {
		                        chain__et = CHAIN_Running_TRANS_tr6_FROM_CarGreen_TO_CarYellowBeforeStandby_BY_standbyfct;
		                        catching_state__et = STATE_Running;
		                    }
		                break;
		                default:
		                    /* should not occur */
		                    break;
		        }
		        break;
		    case STATE_Running_CarRed:
		        switch(trigger__et) {
		                case TRIG_to__timeout:
		                    {
		                        chain__et = CHAIN_Running_TRANS_tr4_FROM_CarRed_TO_PedGreen_BY_timeoutto;
		                        catching_state__et = STATE_Running;
		                    }
		                break;
		                case TRIG_fct__standby:
		                    {
		                        chain__et = CHAIN_TRANS_tr2_FROM_Running_TO_AllRedBeforeStandby_BY_standbyfct;
		                        catching_state__et = STATE_TOP;
		                    }
		                break;
		                default:
		                    /* should not occur */
		                    break;
		        }
		        break;
		    case STATE_Running_PedGreen:
		        switch(trigger__et) {
		                case TRIG_to__timeout:
		                    {
		                        chain__et = CHAIN_Running_TRANS_tr5_FROM_PedGreen_TO_AllRed_BY_timeoutto;
		                        catching_state__et = STATE_Running;
		                    }
		                break;
		                case TRIG_fct__standby:
		                    {
		                        chain__et = CHAIN_TRANS_tr2_FROM_Running_TO_AllRedBeforeStandby_BY_standbyfct;
		                        catching_state__et = STATE_TOP;
		                    }
		                break;
		                default:
		                    /* should not occur */
		                    break;
		        }
		        break;
		    case STATE_Running_CarYellowBeforeStandby:
		        switch(trigger__et) {
		                case TRIG_to__timeout:
		                    {
		                        chain__et = CHAIN_Running_TRANS_tr7_FROM_CarYellowBeforeStandby_TO_tpStandby_BY_timeoutto;
		                        catching_state__et = STATE_Running;
		                    }
		                break;
		                case TRIG_fct__standby:
		                    {
		                        chain__et = CHAIN_TRANS_tr2_FROM_Running_TO_AllRedBeforeStandby_BY_standbyfct;
		                        catching_state__et = STATE_TOP;
		                    }
		                break;
		                default:
		                    /* should not occur */
		                    break;
		        }
		        break;
		    case STATE_Running_CarRedYellow:
		        switch(trigger__et) {
		                case TRIG_to__timeout:
		                    {
		                        chain__et = CHAIN_Running_TRANS_tr8_FROM_CarRedYellow_TO_CarGreen_BY_timeoutto;
		                        catching_state__et = STATE_Running;
		                    }
		                break;
		                case TRIG_fct__standby:
		                    {
		                        chain__et = CHAIN_TRANS_tr2_FROM_Running_TO_AllRedBeforeStandby_BY_standbyfct;
		                        catching_state__et = STATE_TOP;
		                    }
		                break;
		                default:
		                    /* should not occur */
		                    break;
		        }
		        break;
		    case STATE_AllRedBeforeStandby:
		        switch(trigger__et) {
		                case TRIG_to__timeout:
		                    {
		                        chain__et = CHAIN_TRANS_tr4_FROM_AllRedBeforeStandby_TO_Standby_tp0_BY_timeoutto;
		                        catching_state__et = STATE_TOP;
		                    }
		                break;
		                default:
		                    /* should not occur */
		                    break;
		        }
		        break;
		    case STATE_Connecting:
		        switch(trigger__et) {
		                case TRIG_tlInterface__connected:
		                    {
		                        chain__et = CHAIN_TRANS_tr6_FROM_Connecting_TO_Standby_tp0_BY_connectedtlInterface;
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
static void PedestrianTrafficLightController_receiveEvent(PedestrianTrafficLightController* self, InterfaceItemBase* ifitem, int evt, void* generic_data__et) {
	int localId = (ifitem==NULL)? 0 : ifitem->localId;
	PedestrianTrafficLightController_receiveEventInternal(self, ifitem, localId, evt, generic_data__et);
}

void PedestrianTrafficLightController_init(PedestrianTrafficLightController* self){
	ET_MSC_LOGGER_SYNC_ENTRY("PedestrianTrafficLightController", "init")
	self->state = STATE_TOP;
	{
		int i;
		for (i=0; i<PEDESTRIANTRAFFICLIGHTCONTROLLER_HISTORY_SIZE; ++i)
			self->history[i] = NO_STATE;
	}
	PedestrianTrafficLightController_executeInitTransition(self);
	ET_MSC_LOGGER_SYNC_EXIT
}


void PedestrianTrafficLightController_receiveMessage(void* self, const void* ifitem, const etMessage* msg){
	ET_MSC_LOGGER_SYNC_ENTRY("PedestrianTrafficLightController", "_receiveMessage")
	PedestrianTrafficLightController_receiveEvent(self, (etPort*)ifitem, msg->evtID, (void*)(((char*)msg)+MEM_CEIL(sizeof(etMessage))));

	ET_MSC_LOGGER_SYNC_EXIT
}


/*--------------------- user constructor/destructor ---------------------*/

/*--------------------- operations ---------------------*/

