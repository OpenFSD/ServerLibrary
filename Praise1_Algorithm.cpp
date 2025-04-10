#include "pch.h"
#include "GameInstance.h"
#include "Praise1_Algorithm.h"
#include <cstddef>

namespace Server_Library
{
    Praise1_Algorithm::Praise1_Algorithm()
    {
    }

    Praise1_Algorithm::~Praise1_Algorithm()
    {
    }

    void Praise1_Algorithm::Do_Praise(
        class Server_Library::Praise1_Input* ptr_In_SubSet,
        class Server_Library::Praise1_Output* ptr_Out_SubSet
    )
    {
        std::vector<float> _Position;
        _Position.resize(2);
        if (Server_Library::Framework_Server::Get_HostServer()->Get_Data()->GetGameInstance()->GetPlayer(0)->Get_isFirstMove() == true) // This bool variable is initially set to true.
        {
            _Position = { ptr_In_SubSet->Get_mouse_X(), ptr_In_SubSet->Get_mouse_Y() };
            Server_Library::Framework_Server::Get_HostServer()->Get_Data()->GetGameInstance()->GetPlayer(0)->Set_isFirstMove(false);
        }
        else
        {
            // Calculate the offset of the mouse position
            float deltaX = Server_Library::Framework_Server::Get_HostServer()->Get_Data()->GetGameInstance()->GetPlayer(0)->Get_MousePos().at(0) - ptr_In_SubSet->Get_mouse_X();
            float deltaY = Server_Library::Framework_Server::Get_HostServer()->Get_Data()->GetGameInstance()->GetPlayer(0)->Get_MousePos().at(1) - ptr_In_SubSet->Get_mouse_Y();
            _Position = { ptr_In_SubSet->Get_mouse_X(), ptr_In_SubSet->Get_mouse_Y() };
            Server_Library::Framework_Server::Get_HostServer()->Get_Data()->GetGameInstance()->GetPlayer(0)->Set_MousePos(_Position);

            // Apply the camera pitch and yaw (we clamp the pitch in the camera class)
            ptr_Out_SubSet->SetYaw(ptr_Out_SubSet->GetYaw() + (deltaX * Server_Library::Framework_Server::Get_HostServer()->Get_Data()->GetGameInstance()->GetPlayer(0)->Get_Sensativity()));
            //ToDo if greater the n 360 equal zero
            ptr_Out_SubSet->SetPitch(ptr_Out_SubSet->GetPitch() + (deltaY * Server_Library::Framework_Server::Get_HostServer()->Get_Data()->GetGameInstance()->GetPlayer(0)->Get_Sensativity()));
            //ToDo if greater the n 360 equal zero
        }
    }
}