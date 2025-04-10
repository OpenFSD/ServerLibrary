#include "pch.h"
#include "Framework_Server.h"
#include <cstddef>
#include <iostream>

namespace Server_Library
{
	class Server_Library::Server* Framework_Server::ptr_HostServer;

	Framework_Server::Framework_Server()
	{
		std::cout << "entered => Framework_Server::Framework_Server()" << std::endl;
	}

	Framework_Server::~Framework_Server()
	{

	}

	void Framework_Server::Create_Hosting_Server()
	{
		ptr_HostServer = new class Server_Library::Server();
		while (ptr_HostServer == NULL) { /* wait untill created */ }
		std::cout << "Created => Server_Library::Server()" << std::endl;
		ptr_HostServer->Get_Execute()->Initialise();

		ptr_HostServer->Get_Data()->Initialise_GameInstance();

		ptr_HostServer->Get_Execute()->Initialise_Threads();
	}

	class Server_Library::Server* Framework_Server::Get_HostServer()
	{
		return ptr_HostServer;
	}
}