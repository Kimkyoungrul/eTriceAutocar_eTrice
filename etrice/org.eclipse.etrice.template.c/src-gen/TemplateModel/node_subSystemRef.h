/**
 * @author generated by eTrice
 *
 * Header File of Node node with SubSystem subSystemRef
 *
 */

#ifndef _NODE_SUBSYSTEMREF_H_
#define _NODE_SUBSYSTEMREF_H_

#include "etDatatypes.h"



/* lifecycle functions
 * init -> start -> run (loop) -> stop -> destroy
 */

void node_subSystemRef_init(void);		/* lifecycle init  	 */
void node_subSystemRef_start(void);	/* lifecycle start 	 */

void node_subSystemRef_run(etBool runAsTest);		/* lifecycle run 	 */

void node_subSystemRef_stop(void); 	/* lifecycle stop	 */
void node_subSystemRef_destroy(void); 	/* lifecycle destroy */

void node_subSystemRef_shutdown(void);  /* shutdown the dispatcher loop */


#endif /* _NODE_SUBSYSTEMREF_H_ */

