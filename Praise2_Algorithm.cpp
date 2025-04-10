#include "pch.h"
#include "Praise2_Algorithm.h"
#include <vector>
#include <cstddef>

namespace Server_Library
{
    Praise2_Algorithm::Praise2_Algorithm()
    {
    }

    Praise2_Algorithm::~Praise2_Algorithm()
    {
    }

    void Praise2_Algorithm::Do_Praise(
        class Server_Library::Praise2_Input* ptr_In_SubSet,
        class Server_Library::Praise2_Output* ptr_Out_SubSet
    )
    {
        std::vector<float> _Position;
        _Position.resize(3);
        if (ptr_In_SubSet->Get_fowards() == true && ptr_In_SubSet->Get_backwards() == true)
        {
            //nill propergation
        }
        else if (ptr_In_SubSet->Get_fowards() == true)
        {
            _Position.at(0) = Server_Library::Framework_Server::Get_HostServer()->Get_Data()->GetGameInstance()->GetPlayer(0)->Get_PlayerPosition().at(0);
            _Position.at(1) = Server_Library::Framework_Server::Get_HostServer()->Get_Data()->GetGameInstance()->GetPlayer(0)->Get_PlayerPosition().at(1);
            _Position.at(2) = Server_Library::Framework_Server::Get_HostServer()->Get_Data()->GetGameInstance()->GetPlayer(0)->Get_PlayerPosition().at(2);
            
            _Position[0] += Server_Library::Framework_Server::Get_HostServer()->Get_Data()->GetGameInstance()->GetPlayer(0)->Get_Front()[0] * Server_Library::Framework_Server::Get_HostServer()->Get_Data()->GetGameInstance()->GetPlayer(0)->Get_CameraSpeed() * ptr_In_SubSet->Get_period();
            _Position[1] += Server_Library::Framework_Server::Get_HostServer()->Get_Data()->GetGameInstance()->GetPlayer(0)->Get_Front()[1] * Server_Library::Framework_Server::Get_HostServer()->Get_Data()->GetGameInstance()->GetPlayer(0)->Get_CameraSpeed() * ptr_In_SubSet->Get_period();
            _Position[2] += Server_Library::Framework_Server::Get_HostServer()->Get_Data()->GetGameInstance()->GetPlayer(0)->Get_Front()[2] * Server_Library::Framework_Server::Get_HostServer()->Get_Data()->GetGameInstance()->GetPlayer(0)->Get_CameraSpeed() * ptr_In_SubSet->Get_period();
            
            ptr_Out_SubSet->Set_position(_Position);
        }
        else if (ptr_In_SubSet->Get_backwards() == true)
        {
            _Position.at(0) = Server_Library::Framework_Server::Get_HostServer()->Get_Data()->GetGameInstance()->GetPlayer(0)->Get_PlayerPosition().at(0);
            _Position.at(1) = Server_Library::Framework_Server::Get_HostServer()->Get_Data()->GetGameInstance()->GetPlayer(0)->Get_PlayerPosition().at(1);
            _Position.at(2) = Server_Library::Framework_Server::Get_HostServer()->Get_Data()->GetGameInstance()->GetPlayer(0)->Get_PlayerPosition().at(2);

            _Position[0] -= Server_Library::Framework_Server::Get_HostServer()->Get_Data()->GetGameInstance()->GetPlayer(0)->Get_Front()[0] * Server_Library::Framework_Server::Get_HostServer()->Get_Data()->GetGameInstance()->GetPlayer(0)->Get_CameraSpeed() * ptr_In_SubSet->Get_period();
            _Position[1] -= Server_Library::Framework_Server::Get_HostServer()->Get_Data()->GetGameInstance()->GetPlayer(0)->Get_Front()[1] * Server_Library::Framework_Server::Get_HostServer()->Get_Data()->GetGameInstance()->GetPlayer(0)->Get_CameraSpeed() * ptr_In_SubSet->Get_period();
            _Position[2] -= Server_Library::Framework_Server::Get_HostServer()->Get_Data()->GetGameInstance()->GetPlayer(0)->Get_Front()[2] * Server_Library::Framework_Server::Get_HostServer()->Get_Data()->GetGameInstance()->GetPlayer(0)->Get_CameraSpeed() * ptr_In_SubSet->Get_period();

            ptr_Out_SubSet->Set_position(_Position);
        }
        if (ptr_In_SubSet->Get_right() == true && ptr_In_SubSet->Get_left() == true)
        {
            //nill propergation
        }
        else if (ptr_In_SubSet->Get_right() == true)
        {
            _Position.at(0) = Server_Library::Framework_Server::Get_HostServer()->Get_Data()->GetGameInstance()->GetPlayer(0)->Get_PlayerPosition().at(0);
            _Position.at(1) = Server_Library::Framework_Server::Get_HostServer()->Get_Data()->GetGameInstance()->GetPlayer(0)->Get_PlayerPosition().at(1);
            _Position.at(2) = Server_Library::Framework_Server::Get_HostServer()->Get_Data()->GetGameInstance()->GetPlayer(0)->Get_PlayerPosition().at(2);

            _Position[0] += Server_Library::Framework_Server::Get_HostServer()->Get_Data()->GetGameInstance()->GetPlayer(0)->Get_Right()[0] * Server_Library::Framework_Server::Get_HostServer()->Get_Data()->GetGameInstance()->GetPlayer(0)->Get_CameraSpeed() * ptr_In_SubSet->Get_period();
            _Position[1] += Server_Library::Framework_Server::Get_HostServer()->Get_Data()->GetGameInstance()->GetPlayer(0)->Get_Right()[1] * Server_Library::Framework_Server::Get_HostServer()->Get_Data()->GetGameInstance()->GetPlayer(0)->Get_CameraSpeed() * ptr_In_SubSet->Get_period();
            _Position[2] += Server_Library::Framework_Server::Get_HostServer()->Get_Data()->GetGameInstance()->GetPlayer(0)->Get_Right()[2] * Server_Library::Framework_Server::Get_HostServer()->Get_Data()->GetGameInstance()->GetPlayer(0)->Get_CameraSpeed() * ptr_In_SubSet->Get_period();

            ptr_Out_SubSet->Set_position(_Position);
        }
        else if (ptr_In_SubSet->Get_left() == true)
        {
            _Position.at(0) = Server_Library::Framework_Server::Get_HostServer()->Get_Data()->GetGameInstance()->GetPlayer(0)->Get_PlayerPosition().at(0);
            _Position.at(1) = Server_Library::Framework_Server::Get_HostServer()->Get_Data()->GetGameInstance()->GetPlayer(0)->Get_PlayerPosition().at(1);
            _Position.at(2) = Server_Library::Framework_Server::Get_HostServer()->Get_Data()->GetGameInstance()->GetPlayer(0)->Get_PlayerPosition().at(2);

            _Position[0] -= Server_Library::Framework_Server::Get_HostServer()->Get_Data()->GetGameInstance()->GetPlayer(0)->Get_Right()[0] * Server_Library::Framework_Server::Get_HostServer()->Get_Data()->GetGameInstance()->GetPlayer(0)->Get_CameraSpeed() * ptr_In_SubSet->Get_period();
            _Position[1] -= Server_Library::Framework_Server::Get_HostServer()->Get_Data()->GetGameInstance()->GetPlayer(0)->Get_Right()[1] * Server_Library::Framework_Server::Get_HostServer()->Get_Data()->GetGameInstance()->GetPlayer(0)->Get_CameraSpeed() * ptr_In_SubSet->Get_period();
            _Position[2] -= Server_Library::Framework_Server::Get_HostServer()->Get_Data()->GetGameInstance()->GetPlayer(0)->Get_Right()[2] * Server_Library::Framework_Server::Get_HostServer()->Get_Data()->GetGameInstance()->GetPlayer(0)->Get_CameraSpeed() * ptr_In_SubSet->Get_period();

            ptr_Out_SubSet->Set_position(_Position);
        }
        ptr_Out_SubSet->Set_front(Server_Library::Framework_Server::Get_HostServer()->Get_Data()->GetGameInstance()->GetPlayer(0)->Get_Front());
        ptr_Out_SubSet->Set_right(Server_Library::Framework_Server::Get_HostServer()->Get_Data()->GetGameInstance()->GetPlayer(0)->Get_Right());
        ptr_Out_SubSet->Set_up(Server_Library::Framework_Server::Get_HostServer()->Get_Data()->GetGameInstance()->GetPlayer(0)->Get_Up());
    }
}