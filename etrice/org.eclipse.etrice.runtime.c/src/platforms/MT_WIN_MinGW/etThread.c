/*******************************************************************************
 * Copyright (c) 2013 protos software gmbh (http://www.protos.de).
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *
 * CONTRIBUTORS:
 * 		Thomas Schuetz, Thomas Jung (initial contribution)
 *
 *******************************************************************************/

/**
 *
 * etThread.c MinGW implementation of etThread
 *
 */

#include "osal/etThread.h"

#include "debugging/etLogger.h"
#include "debugging/etMSCLogger.h"
#include <string.h>
#include <process.h>
void etThread_execute(etThread* self);
int j=0;
void etThread_construct(
		etThread* self,
		etStacksize stacksize,
		etPriority priority,
		etThreadname threadName,
		etThreadFunction threadFunction,
		void* threadFunctionData,
		etCpunum cpunum)//added by kkr cpunum
{
	ET_MSC_LOGGER_SYNC_ENTRY("etThread", "construct")

	/* fill in data */
	self->stacksize = stacksize;
	self->priority = priority;
	self->threadName = threadName;
	self->threadFunction = threadFunction;
	self->threadFunctionData = threadFunctionData;
	self->cpunum = cpunum;//cpunum added by kkr
	ET_MSC_LOGGER_SYNC_EXIT
}

void etThread_start(etThread* self) {
	ET_MSC_LOGGER_SYNC_ENTRY("etThread", "start")
	self->osData = (HANDLE)_beginthread( (etThreadFunction)etThread_execute, self->stacksize, self );
	SetThreadPriority(self->osData, self->priority);
	SetThreadAffinityMask(self->osData, 1 << self->cpunum);//SetThreadAffinityMask added by kkr
	ET_MSC_LOGGER_SYNC_EXIT
}

void etThread_execute(etThread* self){
	ET_MSC_LOGGER_SYNC_ENTRY("etThread", "execute")
	/* etThread_execute redirects the call from the thread to the execute function in the eTrice runtime to enable correct synchronous MSC logging */
	self->threadFunction(self->threadFunctionData);

	ET_MSC_LOGGER_SYNC_EXIT
}

void etThread_destruct(etThread* self){
	ET_MSC_LOGGER_SYNC_ENTRY("etThread", "destruct")
	TerminateThread(self->osData, 0);
	ET_MSC_LOGGER_SYNC_EXIT
}

void etThread_sleep(etInt32 millis){
	ET_MSC_LOGGER_SYNC_ENTRY("etThread", "sleep")
	Sleep(millis);
	ET_MSC_LOGGER_SYNC_EXIT
}

etOSThreadData etThread_self(void){
	return GetCurrentThread();
}

etOSThreadId etThread_self_id(void){
	return GetCurrentThreadId();
}

