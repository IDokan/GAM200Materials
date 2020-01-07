/******************************************************************************
Copyright (C) 2019 DigiPen Institute of Technology.
Reproduction or disclosure of this file or its contents without the prior
written consent of DigiPen Institute of Technology is prohibited.
File Name:   DerivedStates.h
Author
		Dev_Il
		rtd99062@gmail.com
Creation Date: 01.07.2020

	Header file for example states
		When Player run away..
		When Player sleep..
******************************************************************************/
#pragma once
#include "State.h"
#include "Player.h"

class State_RunAway;
class State_Sleep;

// ----------------State_RunAway
class State_RunAway : public State
{
public:
	void Execute(Player* player) override
	{
		if (player->isSafe())
		{
			player->ChangeState(new State_Sleep());
		}
		else
		{
			player->MoveAwayFromEnemy();
		}
	}
};

// ----------------State_Sleep
class State_Sleep : public State
{
public:
	void Execute(Player* player) override
	{
		if (player->isThreatened())
		{
			player->ChangeState(new State_RunAway());
		}
		else
		{
			player->Snore();
		}
	}
};