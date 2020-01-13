/******************************************************************************
Copyright (C) 2019 DigiPen Institute of Technology.
Reproduction or disclosure of this file or its contents without the prior
written consent of DigiPen Institute of Technology is prohibited.
File Name:   MessageCapableEntity.h
Author
		Dev_Il
		rtd99062@gmail.com
Creation Date: 01.09.2020

	Header file for entity which can receive message
******************************************************************************/

class Telegram;

class BaseGameEntity
{
public:
	// all subclasses can communicate using messages.
	virtual bool HandleMessage(const Telegram& msg) = 0;
	

private:
	int m_ID;

	/* EXTRANEOUS DETAIL REMOVED FOR CLARITY */
};