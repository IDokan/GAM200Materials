/******************************************************************************
Copyright (C) 2019 DigiPen Institute of Technology.
Reproduction or disclosure of this file or its contents without the prior
written consent of DigiPen Institute of Technology is prohibited.
File Name:   MessageCapableState.h
Author
		Dev_Il
		rtd99062@gmail.com
Creation Date: 01.09.2020

	Header file for message capable state
******************************************************************************/
#pragma once

class Player;

template<class entity_type>
class State
{
public:
	virtual ~State(){}

	// this will execute when the state is entered
	virtual void Enter(entity_type* player) = 0;
	
	// this is called by the miner's update function each update step
	virtual void Execute(entity_type* player) = 0;

	// this will execute when the state is exited
	virtual void Exit(entity_type* player) = 0;

	//this executes if the agent receives a message from the message dispatcher
	virtual bool OnMessage(entity_type, const Telegram&) = 0;
};


/*		Example can be shown like this...

class Example : public State<Player>
{

};
*/