#include "pch.h"
#include "Concurrent.h"
#include <cstddef>
#include <iostream>


namespace Server_Library
{
    class Concurrent_Control* Concurrent::ptr_Concurrent_Control = NULL;
    class Object* Concurrent::ptr_Algorithms_Subset = NULL;

    Concurrent::Concurrent()
    {
        ptr_Concurrent_Control = NULL;
        ptr_Algorithms_Subset = NULL;
    }

    Concurrent::~Concurrent()
    {
        delete ptr_Concurrent_Control;
        delete ptr_Algorithms_Subset;
    }

    void Concurrent::Initialise_Control()
    {
        ptr_Concurrent_Control = new class Server_Library::Concurrent_Control();
        while (ptr_Concurrent_Control == NULL) { /* wait untill class constructed */ }
    }

    void Concurrent::Thread_Concurrency(__int8 concurrent_coreId, __int8 number_Implemented_Cores)
    {
        bool doneOnce = true;
        while (Server_Library::Framework_Server::Get_HostServer()->Get_Execute()->Get_Execute_Control()->GetFlag_ThreadInitialised(concurrent_coreId) == true)
        {
            if (doneOnce == true)
            {
                Server_Library::Framework_Server::Get_HostServer()->Get_Execute()->Get_Execute_Control()->SetConditionCodeOfThisThreadedCore(concurrent_coreId);
                doneOnce = false;
            }

        }
        std::cout << "Thread Initialised => Thread_Concurrency()" << std::endl;//TestBench
        while (Server_Library::Framework_Server::Get_HostServer()->Get_Execute()->Get_Execute_Control()->GetFlag_SystemInitialised() == true)
        {

        }
        std::cout << "Thread Starting => Thread_Concurrency()" << std::endl;//TestBench
        while (Server_Library::Framework_Server::Get_HostServer()->Get_Execute()->Get_Execute_Control()->GetFlag_SystemInitialised() == false)
        {
            if (Server_Library::Framework_Server::Get_HostServer()->Get_Execute()->Get_LaunchConcurrency_ServerSide()->Get_LaunchConcurrency()->Get_Control_Of_LaunchConcurrency()->Get_State_ConcurrentCore(concurrent_coreId)
                == Server_Library::Framework_Server::Get_HostServer()->Get_Execute()->Get_LaunchConcurrency_ServerSide()->Get_LaunchConcurrency()->Get_GlobalForLaunchConcurrency()->GetConst_Core_IDLE())
            {
                Server_Library::Framework_Server::Get_HostServer()->Get_Execute()->Get_LaunchConcurrency_ServerSide()->Get_LaunchConcurrency()->Get_Control_Of_LaunchConcurrency()->SetFlag_ConcurrentCoreState(
                    concurrent_coreId,
                    Server_Library::Framework_Server::Get_HostServer()->Get_Execute()->Get_LaunchConcurrency_ServerSide()->Get_LaunchConcurrency()->Get_GlobalForLaunchConcurrency()->GetConst_Core_ACTIVE()
                );
                if (Server_Library::Framework_Server::Get_HostServer()->Get_Data()->Get_Data_Control()->GetFlag_InputStackLoaded() == true)
                {
                    Server_Library::Framework_Server::Get_HostServer()->Get_Execute()->Get_WriteEnable_Stack_Server_InputPraise()->Write_Start(1 + concurrent_coreId);

                    Server_Library::Framework_Server::Get_HostServer()->Get_Data()->Get_Data_Control()->Pop_Stack_InputPraises(concurrent_coreId);

                    //Server_Library::Framework_Server::Get_HostServer()->Get_Algorithms()->Get_Concurren_Array(concurrent_coreId)->Get_Concurrent_Control()->SelectSet_Algorithm_Subset(
                    //    Server_Library::Framework_Server::Get_HostServer()->Get_Data()->Get_InputRefferenceOfCore(concurrent_coreId)->GetPraiseEventId(),
                   //     concurrent_coreId
                   // );

                  //  Server_Library::Framework_Server::Get_HostServer()->Get_Data()->Get_OutputRefferenceOfCore(concurrent_coreId)->Get_Control_Of_Output()->SelectSet_Output_Subset(
                  //      Server_Library::Framework_Server::Get_HostServer()->Get_Data()->Get_OutputRefferenceOfCore(concurrent_coreId)->GetPraiseEventId(),
                  //      concurrent_coreId
                  //  );

                    Server_Library::Framework_Server::Get_HostServer()->Get_Execute()->Get_WriteEnable_Stack_Server_InputPraise()->Write_End(1 + concurrent_coreId);

                    Server_Library::Framework_Server::Get_HostServer()->Get_Algorithms()->Get_Concurren_Array(concurrent_coreId)->Do_Concurrent_Algorithm_For_PraiseEventId(
                        Server_Library::Framework_Server::Get_HostServer()->Get_Data()->Get_InputRefferenceOfCore(concurrent_coreId)->GetPraiseEventId(),
                        Server_Library::Framework_Server::Get_HostServer()->Get_Algorithms()->Get_Concurren_Array(concurrent_coreId)->Get_Algorithm_Subset(),
                        Server_Library::Framework_Server::Get_HostServer()->Get_Data()->Get_InputRefferenceOfCore(concurrent_coreId)->Get_InputBuffer_Subset(),
                        Server_Library::Framework_Server::Get_HostServer()->Get_Data()->Get_OutputRefferenceOfCore(concurrent_coreId)->Get_OutputBuffer_Subset()
                    );
                    Server_Library::Framework_Server::Get_HostServer()->Get_Execute()->Get_WriteEnable_Stack_Server_OutputPraise()->Write_Start(1 + concurrent_coreId);

                    Server_Library::Framework_Server::Get_HostServer()->Get_Data()->Get_Data_Control()->Push_Stack_Output(concurrent_coreId);

                    Server_Library::Framework_Server::Get_HostServer()->Get_Execute()->Get_LaunchConcurrency_ServerSide()->Thread_End(concurrent_coreId);

                    if (Server_Library::Framework_Server::Get_HostServer()->Get_Data()->Get_Data_Control()->GetFlag_OutputStackLoaded() == true)
                    {
                        if (Server_Library::Framework_Server::Get_HostServer()->Get_Execute()->Get_LaunchConcurrency_ServerSide()->Get_LaunchConcurrency()->Get_Control_Of_LaunchConcurrency()->Get_State_ConcurrentCore(Server_Library::Framework_Server::Get_HostServer()->Get_Execute()->Get_LaunchConcurrency_ServerSide()->Get_LaunchConcurrency()->Get_Control_Of_LaunchConcurrency()->Get_coreId_To_Launch())
                            == Server_Library::Framework_Server::Get_HostServer()->Get_Execute()->Get_LaunchConcurrency_ServerSide()->Get_LaunchConcurrency()->Get_GlobalForLaunchConcurrency()->GetConst_Core_IDLE())
                        {
                            Server_Library::Framework_Server::Get_HostServer()->Get_Execute()->Get_LaunchConcurrency_ServerSide()->Request_Wait_Launch(
                                Server_Library::Framework_Server::Get_HostServer()->Get_Execute()->Get_LaunchConcurrency_ServerSide()->Get_coreId_To_Launch()
                            );
                        }
                    }
                    Server_Library::Framework_Server::Get_HostServer()->Get_Execute()->Get_WriteEnable_Stack_Server_OutputPraise()->Write_End(1 + concurrent_coreId);
                }
            }
        }
    }

    void  Concurrent::Do_Concurrent_Algorithm_For_PraiseEventId(
        __int8 ptr_praiseEventId,
        Object* ptr_Algorithm_Subset,
        Object* ptr_Input_Subset,
        Object* ptr_Output_Subset
    )
    {
        Server_Library::Praise0_Algorithm* ptr_Algorithm_Subset_Praise0 = NULL;
        Server_Library::Praise0_Input* ptr_Input_Subset_Praise0 = NULL;
        Server_Library::Praise0_Output* ptr_Output_Subset_Praise0 = NULL;
        Server_Library::Praise1_Algorithm* ptr_Algorithm_Subset_Praise1 = NULL;
        Server_Library::Praise1_Input* ptr_Input_Subset_Praise1 = NULL;
        Server_Library::Praise1_Output* ptr_Output_Subset_Praise1 = NULL;
        Server_Library::Praise2_Algorithm* ptr_Algorithm_Subset_Praise2 = NULL;
        Server_Library::Praise2_Input* ptr_Input_Subset_Praise2 = NULL;
        Server_Library::Praise2_Output* ptr_Output_Subset_Praise2 = NULL;
        switch (ptr_praiseEventId)
        {
        case 0:
            ptr_Algorithm_Subset_Praise0 = reinterpret_cast <Server_Library::Praise0_Algorithm*> (ptr_Algorithm_Subset);
            ptr_Input_Subset_Praise0 = reinterpret_cast <Server_Library::Praise0_Input*> (ptr_Input_Subset);
            ptr_Output_Subset_Praise0 = reinterpret_cast <Server_Library::Praise0_Output*> (ptr_Output_Subset);
            ptr_Algorithm_Subset_Praise0->Do_Praise(
                ptr_Input_Subset_Praise0,
                ptr_Output_Subset_Praise0
            );
            break;

        case 1: {
              ptr_Algorithm_Subset_Praise1 = reinterpret_cast <Server_Library::Praise1_Algorithm*> (ptr_Algorithm_Subset);
              ptr_Input_Subset_Praise1 = reinterpret_cast <Server_Library::Praise1_Input*> (ptr_Input_Subset);
              ptr_Output_Subset_Praise1 = reinterpret_cast <Server_Library::Praise1_Output*> (ptr_Output_Subset);
              ptr_Algorithm_Subset_Praise1->Do_Praise(
                  ptr_Input_Subset_Praise1,
                  ptr_Output_Subset_Praise1
              );
        }
            break;

        case 2:
            ptr_Algorithm_Subset_Praise2 = reinterpret_cast <Server_Library::Praise2_Algorithm*> (ptr_Algorithm_Subset);
            ptr_Input_Subset_Praise2 = reinterpret_cast <Server_Library::Praise2_Input*> (ptr_Input_Subset);
            ptr_Output_Subset_Praise2 = reinterpret_cast <Server_Library::Praise2_Output*> (ptr_Output_Subset);
            ptr_Algorithm_Subset_Praise2->Do_Praise(
                ptr_Input_Subset_Praise2,
                ptr_Output_Subset_Praise2
            );
            break;
        }
    }

    class Object* Concurrent::Get_Algorithm_Subset()
    {
        return ptr_Algorithms_Subset;
    }

    class Concurrent_Control* Concurrent::Get_Concurrent_Control()
    {
        return ptr_Concurrent_Control;
    }

    void Concurrent::Set_Algorithm_Subset(class Object* value_algorithm)
    {
        ptr_Algorithms_Subset = value_algorithm;
    }
}