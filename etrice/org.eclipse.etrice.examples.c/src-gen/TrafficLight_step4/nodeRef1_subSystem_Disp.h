/**
 * @author generated by eTrice
 *
 * Dispatcher File of Node nodeRef1 with SubSystem subSystem
 * contains a generated message dispatcher (receiveMessage) for each MessageService (Thread)
 */

#include "messaging/etMessageReceiver.h"
#include "debugging/etLogger.h"
#include "debugging/etMSCLogger.h"


/**
 * generated execute function for all cyclic execute calls for the async or datadriven actor instances of thread "PhysicalThread1"
 */
static void MsgDispatcher_PhysicalThread1_poll(void){
	ET_MSC_LOGGER_SYNC_ENTRY("MsgDispatcher_PhysicalThread1", "execute")
	ATimingService_execute((void*)&_TrafficLight_subSystem_timingService);
	ET_MSC_LOGGER_SYNC_EXIT
}

/**
 * generated dispatch function for all messages for the thread "PhysicalThread1"
 */
static etBool MsgDispatcher_PhysicalThread1_receiveMessage(const etMessage* msg){
	ET_MSC_LOGGER_SYNC_ENTRY("MsgDispatcher_PhysicalThread1", "receiveMessage")
	switch(msg->address){

		case MESSAGESERVICE_ADDRESS:
			if (msg->evtID == etSystemProtocol_IN_poll) {
				MsgDispatcher_PhysicalThread1_poll();
			}
			else
			if (msg->evtID == etSystemProtocol_IN_terminate)
				return ET_FALSE;
			break;

		/* interface items of /TrafficLight/subSystem/timingService */
		case 2+BASE_ADDRESS:
			ET_MSC_LOGGER_ASYNC_IN(
				_TrafficLight_subSystem_timingService_const.timer.ports[0].port.peerInstName,
				PTimer_getMessageString(msg->evtID),
				_TrafficLight_subSystem_timingService_const.timer.ports[0].port.myInstName
				)
			ATimingService_receiveMessage((void*)&_TrafficLight_subSystem_timingService,&_TrafficLight_subSystem_timingService_const.timer.ports[0].port, msg);
		break;
		case 3+BASE_ADDRESS:
			ET_MSC_LOGGER_ASYNC_IN(
				_TrafficLight_subSystem_timingService_const.timer.ports[1].port.peerInstName,
				PTimer_getMessageString(msg->evtID),
				_TrafficLight_subSystem_timingService_const.timer.ports[1].port.myInstName
				)
			ATimingService_receiveMessage((void*)&_TrafficLight_subSystem_timingService,&_TrafficLight_subSystem_timingService_const.timer.ports[1].port, msg);
		break;
		case 4+BASE_ADDRESS:
			ET_MSC_LOGGER_ASYNC_IN(
				_TrafficLight_subSystem_timingService_const.timer.ports[2].port.peerInstName,
				PTimer_getMessageString(msg->evtID),
				_TrafficLight_subSystem_timingService_const.timer.ports[2].port.myInstName
				)
			ATimingService_receiveMessage((void*)&_TrafficLight_subSystem_timingService,&_TrafficLight_subSystem_timingService_const.timer.ports[2].port, msg);
		break;

		/* interface items of /TrafficLight/subSystem/step4_HierarchicalReplication */

		/* interface items of /TrafficLight/subSystem/step4_HierarchicalReplication/controllerWithInfrastructure:0 */

		/* interface items of /TrafficLight/subSystem/step4_HierarchicalReplication/controllerWithInfrastructure:0/controller */
		case 8+BASE_ADDRESS:
			ET_MSC_LOGGER_ASYNC_IN(
				((etPort*)&_TrafficLight_subSystem_step4_HierarchicalReplication_controllerWithInfrastructure_0_controller_const.fct)->peerInstName,
				PTrafficLightController_getMessageString(msg->evtID),
				((etPort*)&_TrafficLight_subSystem_step4_HierarchicalReplication_controllerWithInfrastructure_0_controller_const.fct)->myInstName
				)
			PedestrianTrafficLightController_receiveMessage((void*)&_TrafficLight_subSystem_step4_HierarchicalReplication_controllerWithInfrastructure_0_controller,(etPort*)&_TrafficLight_subSystem_step4_HierarchicalReplication_controllerWithInfrastructure_0_controller_const.fct, msg);
			break;
		case 9+BASE_ADDRESS:
			ET_MSC_LOGGER_ASYNC_IN(
				((etPort*)&_TrafficLight_subSystem_step4_HierarchicalReplication_controllerWithInfrastructure_0_controller_const.tlInterface)->peerInstName,
				PTrafficLightInterface_getMessageString(msg->evtID),
				((etPort*)&_TrafficLight_subSystem_step4_HierarchicalReplication_controllerWithInfrastructure_0_controller_const.tlInterface)->myInstName
				)
			PedestrianTrafficLightController_receiveMessage((void*)&_TrafficLight_subSystem_step4_HierarchicalReplication_controllerWithInfrastructure_0_controller,(etPort*)&_TrafficLight_subSystem_step4_HierarchicalReplication_controllerWithInfrastructure_0_controller_const.tlInterface, msg);
			break;
		case 10+BASE_ADDRESS:
			switch (msg->evtID){
				case PTimer_OUT_timeout:
					PTimerConjPort_timeout_receiveHandler((etPort *)&_TrafficLight_subSystem_step4_HierarchicalReplication_controllerWithInfrastructure_0_controller_const.to,msg,(void*)&_TrafficLight_subSystem_step4_HierarchicalReplication_controllerWithInfrastructure_0_controller,PedestrianTrafficLightController_receiveMessage);
					break;
				default: PedestrianTrafficLightController_receiveMessage((void*)&_TrafficLight_subSystem_step4_HierarchicalReplication_controllerWithInfrastructure_0_controller,(etPort*)&_TrafficLight_subSystem_step4_HierarchicalReplication_controllerWithInfrastructure_0_controller_const.to, msg);
					break;
			}
			break;

		/* interface items of /TrafficLight/subSystem/step4_HierarchicalReplication/controllerWithInfrastructure:0/tlInterface */
		case 12+BASE_ADDRESS:
			ET_MSC_LOGGER_ASYNC_IN(
				((etPort*)&_TrafficLight_subSystem_step4_HierarchicalReplication_controllerWithInfrastructure_0_tlInterface_const.fct)->peerInstName,
				PTrafficLightInterface_getMessageString(msg->evtID),
				((etPort*)&_TrafficLight_subSystem_step4_HierarchicalReplication_controllerWithInfrastructure_0_tlInterface_const.fct)->myInstName
				)
			TrafficLightInterface_receiveMessage((void*)&_TrafficLight_subSystem_step4_HierarchicalReplication_controllerWithInfrastructure_0_tlInterface,(etPort*)&_TrafficLight_subSystem_step4_HierarchicalReplication_controllerWithInfrastructure_0_tlInterface_const.fct, msg);
			break;
		case 13+BASE_ADDRESS:
			ET_MSC_LOGGER_ASYNC_IN(
				((etPort*)&_TrafficLight_subSystem_step4_HierarchicalReplication_controllerWithInfrastructure_0_tlInterface_const.ctrl)->peerInstName,
				PTcpControl_getMessageString(msg->evtID),
				((etPort*)&_TrafficLight_subSystem_step4_HierarchicalReplication_controllerWithInfrastructure_0_tlInterface_const.ctrl)->myInstName
				)
			TrafficLightInterface_receiveMessage((void*)&_TrafficLight_subSystem_step4_HierarchicalReplication_controllerWithInfrastructure_0_tlInterface,(etPort*)&_TrafficLight_subSystem_step4_HierarchicalReplication_controllerWithInfrastructure_0_tlInterface_const.ctrl, msg);
			break;
		case 14+BASE_ADDRESS:
			ET_MSC_LOGGER_ASYNC_IN(
				((etPort*)&_TrafficLight_subSystem_step4_HierarchicalReplication_controllerWithInfrastructure_0_tlInterface_const.payload)->peerInstName,
				PTcpPayload_getMessageString(msg->evtID),
				((etPort*)&_TrafficLight_subSystem_step4_HierarchicalReplication_controllerWithInfrastructure_0_tlInterface_const.payload)->myInstName
				)
			TrafficLightInterface_receiveMessage((void*)&_TrafficLight_subSystem_step4_HierarchicalReplication_controllerWithInfrastructure_0_tlInterface,(etPort*)&_TrafficLight_subSystem_step4_HierarchicalReplication_controllerWithInfrastructure_0_tlInterface_const.payload, msg);
			break;

		/* interface items of /TrafficLight/subSystem/step4_HierarchicalReplication/controllerWithInfrastructure:0/tcpClient */
		case 16+BASE_ADDRESS:
			ET_MSC_LOGGER_ASYNC_IN(
				((etPort*)&_TrafficLight_subSystem_step4_HierarchicalReplication_controllerWithInfrastructure_0_tcpClient_const.controlPort)->peerInstName,
				PTcpControl_getMessageString(msg->evtID),
				((etPort*)&_TrafficLight_subSystem_step4_HierarchicalReplication_controllerWithInfrastructure_0_tcpClient_const.controlPort)->myInstName
				)
			ATcpClient_receiveMessage((void*)&_TrafficLight_subSystem_step4_HierarchicalReplication_controllerWithInfrastructure_0_tcpClient,(etPort*)&_TrafficLight_subSystem_step4_HierarchicalReplication_controllerWithInfrastructure_0_tcpClient_const.controlPort, msg);
			break;
		case 17+BASE_ADDRESS:
			ET_MSC_LOGGER_ASYNC_IN(
				((etPort*)&_TrafficLight_subSystem_step4_HierarchicalReplication_controllerWithInfrastructure_0_tcpClient_const.payloadPort)->peerInstName,
				PTcpPayload_getMessageString(msg->evtID),
				((etPort*)&_TrafficLight_subSystem_step4_HierarchicalReplication_controllerWithInfrastructure_0_tcpClient_const.payloadPort)->myInstName
				)
			ATcpClient_receiveMessage((void*)&_TrafficLight_subSystem_step4_HierarchicalReplication_controllerWithInfrastructure_0_tcpClient,(etPort*)&_TrafficLight_subSystem_step4_HierarchicalReplication_controllerWithInfrastructure_0_tcpClient_const.payloadPort, msg);
			break;

		/* interface items of /TrafficLight/subSystem/step4_HierarchicalReplication/controllerWithInfrastructure:1 */

		/* interface items of /TrafficLight/subSystem/step4_HierarchicalReplication/controllerWithInfrastructure:1/controller */
		case 20+BASE_ADDRESS:
			ET_MSC_LOGGER_ASYNC_IN(
				((etPort*)&_TrafficLight_subSystem_step4_HierarchicalReplication_controllerWithInfrastructure_1_controller_const.fct)->peerInstName,
				PTrafficLightController_getMessageString(msg->evtID),
				((etPort*)&_TrafficLight_subSystem_step4_HierarchicalReplication_controllerWithInfrastructure_1_controller_const.fct)->myInstName
				)
			PedestrianTrafficLightController_receiveMessage((void*)&_TrafficLight_subSystem_step4_HierarchicalReplication_controllerWithInfrastructure_1_controller,(etPort*)&_TrafficLight_subSystem_step4_HierarchicalReplication_controllerWithInfrastructure_1_controller_const.fct, msg);
			break;
		case 21+BASE_ADDRESS:
			ET_MSC_LOGGER_ASYNC_IN(
				((etPort*)&_TrafficLight_subSystem_step4_HierarchicalReplication_controllerWithInfrastructure_1_controller_const.tlInterface)->peerInstName,
				PTrafficLightInterface_getMessageString(msg->evtID),
				((etPort*)&_TrafficLight_subSystem_step4_HierarchicalReplication_controllerWithInfrastructure_1_controller_const.tlInterface)->myInstName
				)
			PedestrianTrafficLightController_receiveMessage((void*)&_TrafficLight_subSystem_step4_HierarchicalReplication_controllerWithInfrastructure_1_controller,(etPort*)&_TrafficLight_subSystem_step4_HierarchicalReplication_controllerWithInfrastructure_1_controller_const.tlInterface, msg);
			break;
		case 22+BASE_ADDRESS:
			switch (msg->evtID){
				case PTimer_OUT_timeout:
					PTimerConjPort_timeout_receiveHandler((etPort *)&_TrafficLight_subSystem_step4_HierarchicalReplication_controllerWithInfrastructure_1_controller_const.to,msg,(void*)&_TrafficLight_subSystem_step4_HierarchicalReplication_controllerWithInfrastructure_1_controller,PedestrianTrafficLightController_receiveMessage);
					break;
				default: PedestrianTrafficLightController_receiveMessage((void*)&_TrafficLight_subSystem_step4_HierarchicalReplication_controllerWithInfrastructure_1_controller,(etPort*)&_TrafficLight_subSystem_step4_HierarchicalReplication_controllerWithInfrastructure_1_controller_const.to, msg);
					break;
			}
			break;

		/* interface items of /TrafficLight/subSystem/step4_HierarchicalReplication/controllerWithInfrastructure:1/tlInterface */
		case 24+BASE_ADDRESS:
			ET_MSC_LOGGER_ASYNC_IN(
				((etPort*)&_TrafficLight_subSystem_step4_HierarchicalReplication_controllerWithInfrastructure_1_tlInterface_const.fct)->peerInstName,
				PTrafficLightInterface_getMessageString(msg->evtID),
				((etPort*)&_TrafficLight_subSystem_step4_HierarchicalReplication_controllerWithInfrastructure_1_tlInterface_const.fct)->myInstName
				)
			TrafficLightInterface_receiveMessage((void*)&_TrafficLight_subSystem_step4_HierarchicalReplication_controllerWithInfrastructure_1_tlInterface,(etPort*)&_TrafficLight_subSystem_step4_HierarchicalReplication_controllerWithInfrastructure_1_tlInterface_const.fct, msg);
			break;
		case 25+BASE_ADDRESS:
			ET_MSC_LOGGER_ASYNC_IN(
				((etPort*)&_TrafficLight_subSystem_step4_HierarchicalReplication_controllerWithInfrastructure_1_tlInterface_const.ctrl)->peerInstName,
				PTcpControl_getMessageString(msg->evtID),
				((etPort*)&_TrafficLight_subSystem_step4_HierarchicalReplication_controllerWithInfrastructure_1_tlInterface_const.ctrl)->myInstName
				)
			TrafficLightInterface_receiveMessage((void*)&_TrafficLight_subSystem_step4_HierarchicalReplication_controllerWithInfrastructure_1_tlInterface,(etPort*)&_TrafficLight_subSystem_step4_HierarchicalReplication_controllerWithInfrastructure_1_tlInterface_const.ctrl, msg);
			break;
		case 26+BASE_ADDRESS:
			ET_MSC_LOGGER_ASYNC_IN(
				((etPort*)&_TrafficLight_subSystem_step4_HierarchicalReplication_controllerWithInfrastructure_1_tlInterface_const.payload)->peerInstName,
				PTcpPayload_getMessageString(msg->evtID),
				((etPort*)&_TrafficLight_subSystem_step4_HierarchicalReplication_controllerWithInfrastructure_1_tlInterface_const.payload)->myInstName
				)
			TrafficLightInterface_receiveMessage((void*)&_TrafficLight_subSystem_step4_HierarchicalReplication_controllerWithInfrastructure_1_tlInterface,(etPort*)&_TrafficLight_subSystem_step4_HierarchicalReplication_controllerWithInfrastructure_1_tlInterface_const.payload, msg);
			break;

		/* interface items of /TrafficLight/subSystem/step4_HierarchicalReplication/controllerWithInfrastructure:1/tcpClient */
		case 28+BASE_ADDRESS:
			ET_MSC_LOGGER_ASYNC_IN(
				((etPort*)&_TrafficLight_subSystem_step4_HierarchicalReplication_controllerWithInfrastructure_1_tcpClient_const.controlPort)->peerInstName,
				PTcpControl_getMessageString(msg->evtID),
				((etPort*)&_TrafficLight_subSystem_step4_HierarchicalReplication_controllerWithInfrastructure_1_tcpClient_const.controlPort)->myInstName
				)
			ATcpClient_receiveMessage((void*)&_TrafficLight_subSystem_step4_HierarchicalReplication_controllerWithInfrastructure_1_tcpClient,(etPort*)&_TrafficLight_subSystem_step4_HierarchicalReplication_controllerWithInfrastructure_1_tcpClient_const.controlPort, msg);
			break;
		case 29+BASE_ADDRESS:
			ET_MSC_LOGGER_ASYNC_IN(
				((etPort*)&_TrafficLight_subSystem_step4_HierarchicalReplication_controllerWithInfrastructure_1_tcpClient_const.payloadPort)->peerInstName,
				PTcpPayload_getMessageString(msg->evtID),
				((etPort*)&_TrafficLight_subSystem_step4_HierarchicalReplication_controllerWithInfrastructure_1_tcpClient_const.payloadPort)->myInstName
				)
			ATcpClient_receiveMessage((void*)&_TrafficLight_subSystem_step4_HierarchicalReplication_controllerWithInfrastructure_1_tcpClient,(etPort*)&_TrafficLight_subSystem_step4_HierarchicalReplication_controllerWithInfrastructure_1_tcpClient_const.payloadPort, msg);
			break;

		/* interface items of /TrafficLight/subSystem/step4_HierarchicalReplication/headquarters2 */
		case 31+BASE_ADDRESS:
			ET_MSC_LOGGER_ASYNC_IN(
				_TrafficLight_subSystem_step4_HierarchicalReplication_headquarters2_const.controllers.ports[0].port.peerInstName,
				PTrafficLightController_getMessageString(msg->evtID),
				_TrafficLight_subSystem_step4_HierarchicalReplication_headquarters2_const.controllers.ports[0].port.myInstName
				)
			TrafficLightHeadquarters_receiveMessage((void*)&_TrafficLight_subSystem_step4_HierarchicalReplication_headquarters2,&_TrafficLight_subSystem_step4_HierarchicalReplication_headquarters2_const.controllers.ports[0].port, msg);
		break;
		case 32+BASE_ADDRESS:
			ET_MSC_LOGGER_ASYNC_IN(
				_TrafficLight_subSystem_step4_HierarchicalReplication_headquarters2_const.controllers.ports[1].port.peerInstName,
				PTrafficLightController_getMessageString(msg->evtID),
				_TrafficLight_subSystem_step4_HierarchicalReplication_headquarters2_const.controllers.ports[1].port.myInstName
				)
			TrafficLightHeadquarters_receiveMessage((void*)&_TrafficLight_subSystem_step4_HierarchicalReplication_headquarters2,&_TrafficLight_subSystem_step4_HierarchicalReplication_headquarters2_const.controllers.ports[1].port, msg);
		break;
		case 33+BASE_ADDRESS:
			switch (msg->evtID){
				case PTimer_OUT_timeout:
					PTimerConjPort_timeout_receiveHandler((etPort *)&_TrafficLight_subSystem_step4_HierarchicalReplication_headquarters2_const.to,msg,(void*)&_TrafficLight_subSystem_step4_HierarchicalReplication_headquarters2,TrafficLightHeadquarters_receiveMessage);
					break;
				default: TrafficLightHeadquarters_receiveMessage((void*)&_TrafficLight_subSystem_step4_HierarchicalReplication_headquarters2,(etPort*)&_TrafficLight_subSystem_step4_HierarchicalReplication_headquarters2_const.to, msg);
					break;
			}
			break;

		default:
			etLogger_logErrorF("MessageService_PhysicalThread1_receiveMessage: address %d does not exist ", msg->address);
			break;
	}
	ET_MSC_LOGGER_SYNC_EXIT
	return ET_TRUE;
}