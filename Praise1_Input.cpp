#include "pch.h"
#include "Praise1_Input.h"

namespace Server_Library
{
	float Praise1_Input::mouse_X;
	float Praise1_Input::mouse_Y;

	Praise1_Input::Praise1_Input()
	{

	}

	Praise1_Input::~Praise1_Input()
	{
	}
	float Praise1_Input::Get_mouse_X()
	{
		return mouse_X;
	}
	float Praise1_Input::Get_mouse_Y()
	{
		return mouse_Y;
	}
	void Praise1_Input::Set_mouse_X(float value)
	{
		mouse_X = value;
	}
	void Praise1_Input::Set_mouse_Y(float value)
	{
		mouse_Y = value;
	}
}