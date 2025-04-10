#include "pch.h"
#include "Praise0_Output.h"

namespace Server_Library
{
	bool Praise0_Output::ping_Active;

	Praise0_Output::Praise0_Output()
	{
		ping_Active = false;
	}

	Praise0_Output::~Praise0_Output()
	{
	}
	bool Praise0_Output::Get_ping_Active()
	{
		return ping_Active;
	}
	void Praise0_Output::Set_ping_Active(bool value)
	{
		ping_Active = value;
	}
}