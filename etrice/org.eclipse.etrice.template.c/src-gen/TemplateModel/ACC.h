/**
 * @author generated by eTrice
 *
 * Header File of ActorClass ACC
 *
 */

#ifndef _TEMPLATEMODEL_ACC_H_
#define _TEMPLATEMODEL_ACC_H_

#include "etDatatypes.h"
#include "messaging/etMessage.h"

/* include all referenced room classes */
#include "TemplateModel/PSendData.h"

/*--------------------- begin user code ---------------------*/
#include <math.h>
/*--------------------- end user code ---------------------*/

typedef struct ACC ACC;

/* const part of ActorClass (ROM) */
typedef struct ACC_const {
	const char* instName;

	/* simple ports */
	const PSendDataPort recvPort;

	/* data receive ports */

	/* saps */

	/* replicated ports */

	/* services */
} ACC_const;


/* constant for state machine data */
#define ACC_HISTORY_SIZE 2

/* variable part of ActorClass (RAM) */
struct ACC {
	const ACC_const* const constData;

	/* data send ports */

	/*--------------------- attributes ---------------------*/
	 char str[40]
	;
	 char send_str[40]
	;
	 charPtr temp_string;
	 float32 velocity;
	 float32 distance;
	 int32 colliderNum;
	 char colliderNum_str[40]
	;
	 float32 steering;
	 float32 trafficLight;
	 char situation_code[40]
	;


	/* state machine variables */
	etInt16 state;
	etInt16 history[ACC_HISTORY_SIZE];
};

void ACC_init(ACC* self);

void ACC_receiveMessage(void* self, const void* ifitem, const etMessage* msg);


/*--------------------- user constructor/destructor ---------------------*/

/*--------------------- operations ---------------------*/
 bool ACC_ACC_choicePoint1(ACC* self, float32 dist, float32 velo, float32 tl, int32 cnum);
 int32 ACC_speed_down(ACC* self, float32 dist, float32 velo);
 int32 ACC_speed_up(ACC* self, float32 dist, float32 velo);
 bool ACC_ACC_choicePoint0(ACC* self, charPtr s_code);


#endif /* _TEMPLATEMODEL_ACC_H_ */

