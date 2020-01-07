/******************************************************************************
Copyright (C) 2019 DigiPen Institute of Technology.
Reproduction or disclosure of this file or its contents without the prior
written consent of DigiPen Institute of Technology is prohibited.
File Name:   Player.cpp
Author
		Dev_Il
		rtd99062@gmail.com
Creation Date: 01.07.2020

	Source file for player who has a finite state machine.
******************************************************************************/

#include "Player.h"
#include "State.h"

void Player::Update()
{
	current_state->Execute(this);
}

void Player::ChangeState(State* newState)
{
	delete current_state;
	current_state = newState;
}
