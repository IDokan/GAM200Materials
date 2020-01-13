/******************************************************************************
Copyright (C) 2019 DigiPen Institute of Technology.
Reproduction or disclosure of this file or its contents without the prior
written consent of DigiPen Institute of Technology is prohibited.
File Name:   MessageDispatcher.cpp
Author
		Dev_Il
		rtd99062@gmail.com
Creation Date: 01.09.2020

	Source file for Message Dispatcher
		It manages dispatching message
******************************************************************************/
#include "MessageDispatcher.h"
#include "EntityManager.h"
#include "Telegram.h"

void MessageDispatcher::DispatchMessage(double delay, int sender, int receiver, int msg, void* ExtraInfo)
{
	// get a pointer to the receiver of the message
	Entity* pReceiver = EntityMgr->GetEntityFromId(receiver);

	// create the telegram
	Telegram telegram(sender, receiver, msg, 0.0, ExtraInfo);

	// if there is no delay, route the telegram immediately
	if (delay <= 0.0)
	{
		Discharge(pReceiver, telegram);
	}
	// else calculate the time when the telegram should be dispatched
	else
	{
		double CurrentTime = Clock->GetCurrentTime();

		telegram.DispatchTime = CurrentTime + delay;

		// and put it in the queue
		PriorityQ.insert(telegram);
	}
}

void MessageDispatcher::DispatchDelayedMessages()
{
	// first get current time
	double CurrentTime = Clock->GetCurrentTime();

	// now peek at the queue to see if any telegrams need dispatching.
	// remove all telegrams from the front of the queue that have gone
	// past their sell-by date
	while (
		(PriorityQ.begin()->DispatchTime < CurrentTime) &&
		(PriorityQ.begin()->DispatchTime > 0)
		)
	{
		// read the telegram from the front of the queue
		Telegram telegram = *PriorityQ.begin();

		// find the recipient
		Entity* pReceiver = EntityMgr->GetEntityFromId(telegram.Receiver);

		// send the telegram to the recipient
		Discharge(pReceiver, telegram);

		// and remove it from the queue
		PriorityQ.erase(PriorityQ.begin());
	}
}
