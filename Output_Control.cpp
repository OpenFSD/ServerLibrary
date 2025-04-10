#include "pch.h"
#include "Output_Control.h"

namespace Server_Library
{
	Output_Control::Output_Control()
	{

	}
	Output_Control::~Output_Control()
	{

	}

	void Output_Control::LoadValuesInToInputSubset(__int8 concurrent_CoreId, __int8 praiseEventId)
	{

	}

	void Output_Control::SelectSet_Output_Subset(
		__int8 ptr_praiseEventId,
		__int8 concurrent_coreId
	)
	{
		switch (ptr_praiseEventId)
		{
		case 0:
			//Server_Library::Framework_Server::Get_HostServer()->Get_Data()->Get_OutputRefferenceOfCore(concurrent_coreId)->Set_OutputBuffer_Subset(
			//	reinterpret_cast<class Object*>(Server_Library::Framework_Server::Get_HostServer()->Get_Data()->Get_User_O()->Get_Praise0_Output())
			//);
			break;

		case 1:
			//TODO Praise 1
			break;
		}
	}
}