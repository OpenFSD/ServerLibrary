#include "pch.h"
#include "User_I.h"
#include <cstddef>

namespace Server_Library
{
	class Praise0_Input* Server_Library::User_I::ptr_Praise0_Input = NULL;
	class Praise1_Input* Server_Library::User_I::ptr_Praise1_Input = NULL;
	class Praise2_Input* Server_Library::User_I::ptr_Praise2_Input = NULL;

	User_I::User_I()
	{
		ptr_Praise0_Input = new class Server_Library::Praise0_Input();
		while (ptr_Praise0_Input == NULL) { /* wait untill class constructed */ }
		ptr_Praise1_Input = new class Server_Library::Praise1_Input();
		while (ptr_Praise1_Input == NULL) { /* wait untill class constructed */ }
		ptr_Praise2_Input = new class Server_Library::Praise2_Input();
		while (ptr_Praise2_Input == NULL) { /* wait untill class constructed */ }
	}
	User_I::~User_I()
	{
		delete ptr_Praise0_Input;
	}

	Praise0_Input* User_I::Get_Praise0_Input()
	{
		return ptr_Praise0_Input;
	}
	Praise1_Input* User_I::Get_Praise1_Input()
	{
		return ptr_Praise1_Input;
	}
	Praise2_Input* User_I::Get_Praise2_Input()
	{
		return ptr_Praise2_Input;
	}
}