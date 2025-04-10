#include "pch.h"
#include "GameInstance.h"
#include <cstddef>

namespace Server_Library
{
	std::vector<class Player*> GameInstance::player;

	GameInstance::GameInstance()
	{
		player.resize(1);
	}

	GameInstance::~GameInstance()
	{
	}

	Player* GameInstance::GetPlayer(__int8 playerId)
	{
		return player[0];
	}
}