/******************************************************************************
Copyright (C) 2019 DigiPen Institute of Technology.
Reproduction or disclosure of this file or its contents without the prior
written consent of DigiPen Institute of Technology is prohibited.
File Name:   Telegram.h
Author
		Dev_Il
		rtd99062@gmail.com
Creation Date: 01.08.2020

	Header file for message structure
		It is transferred and received by Message System

		A message is simply an enumerated type.

		My individual opinion is that "Telegram can be applied template class?"
******************************************************************************/
#pragma once

struct Telegram
{
	// the entity that sent this telegram
	int Sender;

	// the entity that is to receive this telegram
	int Receiver;

	// the message itself. These are all enumerated in the file
	// "MessageTypes.h"
	int Msg;

	// messages can be dispatched immediately or delayed for a specified amount of time.
	// If a delay is necessary, this field is stamped with the time the message should be dispatched.
	double DispatchTime;

	// any additional information that may accompany the message
	void* ExtraInfo;

	/* CONSTRUCTORS OMITTED */
};