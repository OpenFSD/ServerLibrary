#include "pch.h"
#include "Praise2_Output.h"

namespace Server_Library
{
	std::vector<float> Praise2_Output::_position;
	std::vector<float> Praise2_Output::_front;
	std::vector<float> Praise2_Output::_up;
	std::vector<float> Praise2_Output::_right;

	Praise2_Output::Praise2_Output()
	{
		_position.resize(3);
		_front.resize(3);
		_up.resize(3);
		_right.resize(3);
	}

	Praise2_Output::~Praise2_Output()
	{

	}

	std::vector<float> Praise2_Output::Get_position()
	{
		return _position;
	}

	std::vector<float> Praise2_Output::Get_front()
	{
		return _front;
	}

	std::vector<float> Praise2_Output::Get_up()
	{
		return _up;
	}

	std::vector<float> Praise2_Output::Get_right()
	{
		return _right;
	}

	void Praise2_Output::Set_position(std::vector<float> value)
	{
		_position = value;
	}

	void Praise2_Output::Set_front(std::vector<float> value)
	{
		_front = value;
	}

	void Praise2_Output::Set_up(std::vector<float> value)
	{
		_up = value;
	}

	void Praise2_Output::Set_right(std::vector<float> value)
	{
		_right = value;
	}

	
}
