/******************************************************************************
Copyright (C) 2019 DigiPen Institute of Technology.
Reproduction or disclosure of this file or its contents without the prior
written consent of DigiPen Institute of Technology is prohibited.
File Name:   State.h
Author
		Dev_Il
		rtd99062@gmail.com
Creation Date: 01.07.2020

	Header file for abstract state class
		Every State managed by FSM are inherited from it.
******************************************************************************/
#pragma once

class Player;

class State
{
public:
	virtual void Execute(Player* player) = 0;
};