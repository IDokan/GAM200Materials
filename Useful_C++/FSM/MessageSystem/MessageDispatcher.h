/******************************************************************************
Copyright (C) 2019 DigiPen Institute of Technology.
Reproduction or disclosure of this file or its contents without the prior
written consent of DigiPen Institute of Technology is prohibited.
File Name:   MessageDispatcher.h
Author
		Dev_Il
		rtd99062@gmail.com
Creation Date: 01.08.2020

	Header file for Message Dispatcher
		It manages dispatching message
******************************************************************************/
#pragma once
#include <set>

class Telegram;
class Entity;

class MessageDispatcher
{
public:
	// this class is a singleton
	static MessageDispatcher* Instance();

	// send a message to another agent.
	void DispatchMessage(
		double delay, 
		int sender,
		int receiver,
		int msg,
		void* ExtraInfo
	);

	// Send out any delayed messages. 
	// This method is called each time through the main game loop.
	void DispatchDelayedMessages();

private:
	// a std::set is used a sthe container for the delayed messages
	// because of the benefit of automatic sorting and avoidance of duplicates.
	// Messages are sorted by their dispatch time.
	std::set <Telegram> PriorityQ;

	// this method is utilized by DispatchMessage or DispatchDelayedMessages.
	// This method calls the message handling member function of the receiving
	// entity, pReceiver, with the newly created telegram
	void Discharge(Entity* pReciever, const Telegram& msg);

	MessageDispatcher() {}
};

// to make life easier...
#define Dispatch MessageDispatcher::Instance()