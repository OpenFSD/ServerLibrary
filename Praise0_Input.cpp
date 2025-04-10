#include "pch.h"
#include "Praise0_Input.h"

namespace Server_Library
{
	bool Praise0_Input::ping_Active;

	Praise0_Input::Praise0_Input()
	{
		ping_Active = false;
	}

	Praise0_Input::~Praise0_Input()
	{
	
	}

	bool Praise0_Input::Get_ping_Active()
	{
		return ping_Active;
	}

	void Praise0_Input::Set_ping_Active(bool value)
	{
		ping_Active = value;
	}
}