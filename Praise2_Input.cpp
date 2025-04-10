#include "pch.h"
#include "Praise2_Input.h"

namespace Server_Library
{
	bool Praise2_Input::_fowards;
	bool Praise2_Input::_backwards;
	bool Praise2_Input::_left;
	bool Praise2_Input::_right;
	float Praise2_Input::period;

	Praise2_Input::Praise2_Input()
	{
		_fowards = false;
		_backwards = false;
		_left = false;
		_right = false;
		period = 0;
	}

	Praise2_Input::~Praise2_Input()
	{

	}
	
	bool Praise2_Input::Get_fowards()
	{
		return _fowards;
	}
	bool Praise2_Input::Get_backwards()
	{
		return _backwards;
	}
	bool Praise2_Input::Get_left()
	{
		return _left;
	}
	bool Praise2_Input::Get_right()
	{
		return _right;
	}
	float Praise2_Input::Get_period()
	{
		return period;
	}
	void Praise2_Input::Set_fowards(bool value)
	{
		_fowards = value;
	}
	void Praise2_Input::Set_backwards(bool value)
	{
		_backwards = value;
	}
	void Praise2_Input::Set_left(bool value)
	{
		_left = value;
	}
	void Praise2_Input::Set_right(bool value)
	{
		_right = value;
	}
	void Praise2_Input::Set_period(float value)
	{
		period = value;
	}
}