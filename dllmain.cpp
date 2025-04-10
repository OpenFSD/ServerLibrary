// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

extern "C" __declspec(dllexport) void Create_ConcurrentQue()
{
    ConcurrentQue::ConcurrentQue_Server_Framework::Create_ConcurrentQue();
}
extern "C" __declspec(dllexport) void Request_Wait_Launch(unsigned char concurrent_CoreId)
{
    ConcurrentQue::ConcurrentQue_Server_Framework::Request_Wait_Launch(concurrent_CoreId);
}
extern "C" __declspec(dllexport) void Thread_End(unsigned char concurrent_CoreId)
{
    ConcurrentQue::ConcurrentQue_Server_Framework::Thread_End(concurrent_CoreId);
}
extern "C" __declspec(dllexport) __int8 Get_coreId_To_Launch()
{
    return ConcurrentQue::ConcurrentQue_Server_Framework::Get_coreId_To_Launch();
}
extern "C" __declspec(dllexport) bool Get_Flag_Active()
{
    return ConcurrentQue::ConcurrentQue_Server_Framework::Get_Flag_Active();
}
extern "C" __declspec(dllexport) bool Get_Flag_Idle()
{
    return ConcurrentQue::ConcurrentQue_Server_Framework::Get_Flag_Idle();
}
extern "C" __declspec(dllexport) bool Get_State_LaunchBit()
{
    return ConcurrentQue::ConcurrentQue_Server_Framework::Get_State_LaunchBit();
}
extern "C" __declspec(dllexport) void Create_Hosting_Server()
{
    Server_Library::Framework_Server::Create_Hosting_Server();
}
extern "C" __declspec(dllexport) void Flip_InBufferToWrite()
{
    Server_Library::Framework_Server::Get_HostServer()->Get_Data()->Flip_Input_DoubleBuffer();
}
extern "C" __declspec(dllexport) void Flip_OutBufferToWrite()
{
    Server_Library::Framework_Server::Get_HostServer()->Get_Data()->Flip_Output_DoubleBuffer();
}
extern "C" __declspec(dllexport) bool Get_Flag_IsStackLoaded_Server_InputAction()
{
    return Server_Library::Framework_Server::Get_HostServer()->Get_Data()->Get_Data_Control()->GetFlag_InputStackLoaded();
}
extern "C" __declspec(dllexport) bool Get_Flag_IsStackLoaded_Server_OutputRecieve()
{
    return Server_Library::Framework_Server::Get_HostServer()->Get_Data()->Get_Data_Control()->GetFlag_OutputStackLoaded();
}
extern "C" __declspec(dllexport) bool GetFlag_Server_Library_Initialised()
{
    return Server_Library::Framework_Server::Get_HostServer()->Get_Execute()->Get_Execute_Control()->GetFlag_SystemInitialised();
}
extern "C" __declspec(dllexport) void Pop_Stack_Output()
{
    Server_Library::Framework_Server::Get_HostServer()->Get_Data()->Get_Data_Control()->Pop_Stack_Output();
}
extern "C" __declspec(dllexport) void Push_Stack_InputPraises()
{
    Server_Library::Framework_Server::Get_HostServer()->Get_Data()->Get_Data_Control()->Push_Stack_InputPraises();
}
extern "C" __declspec(dllexport) __int8 Get_PraiseEventId()
{
    return Server_Library::Framework_Server::Get_HostServer()->Get_Data()->GetBuffer_OutputBackDouble()->GetPraiseEventId();
}
extern "C" __declspec(dllexport) float Get_Praise1_pitch()
{
    return reinterpret_cast <class Server_Library::Praise1_Output*>(Server_Library::Framework_Server::Get_HostServer()->Get_Data()->GetBuffer_OututFrontDouble()->Get_OutputBuffer_Subset())->GetPitch();
}
extern "C" __declspec(dllexport) float Get_Praise1_yaw()
{
    return reinterpret_cast <class Server_Library::Praise1_Output*>(Server_Library::Framework_Server::Get_HostServer()->Get_Data()->GetBuffer_OututFrontDouble()->Get_OutputBuffer_Subset())->GetYaw();
}
extern "C" __declspec(dllexport) void Set_PraiseEventId(__int8 value)
{
    Server_Library::Framework_Server::Get_HostServer()->Get_Data()->GetBuffer_InputBackDouble()->SetPraiseEventId(value);
}
extern "C" __declspec(dllexport) void Set_Praise1_mousePos_X(__int16 value)
{
    reinterpret_cast <class Server_Library::Praise1_Input*>(Server_Library::Framework_Server::Get_HostServer()->Get_Data()->GetBuffer_InputFrontDouble()->Get_InputBuffer_Subset())->Set_mouse_X(value);
}
extern "C" __declspec(dllexport) void Set_Praise1_mousePos_Y(__int16 value)
{
    reinterpret_cast <class Server_Library::Praise1_Input*>(Server_Library::Framework_Server::Get_HostServer()->Get_Data()->GetBuffer_InputFrontDouble()->Get_InputBuffer_Subset())->Set_mouse_Y(value);
}
extern "C" __declspec(dllexport) void Create_Write_Stack_Server_OutputSend()
{
    Server_Library::Framework_Server::Get_HostServer()->Get_Execute()->Get_WriteEnable_Stack_Server_OutputPraise()->Create_WriteEnable();
}
extern "C" __declspec(dllexport) void End_Write_Stack_Stack_Server_OutputSend(__int8 value)
{
    Server_Library::Framework_Server::Get_HostServer()->Get_Execute()->Get_WriteEnable_Stack_Server_OutputPraise()->Write_End(value);
}
extern "C" __declspec(dllexport) void Request_Write_Stack_Server_OutputSend(__int8 value)
{
    Server_Library::Framework_Server::Get_HostServer()->Get_Execute()->Get_WriteEnable_Stack_Server_OutputPraise()->Write_Start(value);
}
extern "C" __declspec(dllexport) void Create_Write_Stack_Server_InputAction()
{
    Server_Library::Framework_Server::Get_HostServer()->Get_Execute()->Get_WriteEnable_Stack_Server_InputPraise()->Create_WriteEnable();
}
extern "C" __declspec(dllexport) void End_Write_Stack_Stack_Server_InputAction(__int8 value)
{
    Server_Library::Framework_Server::Get_HostServer()->Get_Execute()->Get_WriteEnable_Stack_Server_InputPraise()->Write_End(value);
}
extern "C" __declspec(dllexport) void Request_Write_Stack_Server_InputAction(__int8 value)
{
    Server_Library::Framework_Server::Get_HostServer()->Get_Execute()->Get_WriteEnable_Stack_Server_InputPraise()->Write_Start(value);
}