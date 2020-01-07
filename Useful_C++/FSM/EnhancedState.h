/******************************************************************************
Copyright (C) 2019 DigiPen Institute of Technology.
Reproduction or disclosure of this file or its contents without the prior
written consent of DigiPen Institute of Technology is prohibited.
File Name:   EnhancedState.h
Author
		Dev_Il
		rtd99062@gmail.com
Creation Date: 01.07.2020

	Header file for enhanced abstract state class
		enhanced version of state class
******************************************************************************/
#pragma once

class Player;

class State
{
public:
	virtual ~State(){}

	// this will execute when the state is entered
	virtual void Enter(Player* player) = 0;
	
	// this is called by the miner's update function each update step
	virtual void Execute(Player* player) = 0;

	// this will execute when the state is exited
	virtual void Exit(Player* player) = 0;
};