/******************************************************************************
Copyright (C) 2019 DigiPen Institute of Technology.
Reproduction or disclosure of this file or its contents without the prior
written consent of DigiPen Institute of Technology is prohibited.
File Name:   Player.h
Author
		Dev_Il
		rtd99062@gmail.com
Creation Date: 01.07.2020

	Header file for player who has a finite state machine.
******************************************************************************/
#pragma once

class State;

class Player
{
public:
	/* INTERFACE TO ATTRIBUTES OMITTED */
	void Update();
	void ChangeState(State* newState);
	
private:
	/* ATTRIBUTES OMITTED */
	State* current_state;
};