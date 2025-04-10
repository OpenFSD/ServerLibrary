#include "pch.h"
#include "Player.h"

namespace Server_Library
{
	bool Player::_firstMove;

	bool Player::isPlayerMoved;
	std::vector<float> Player::player_Position;
	std::vector<float> Player::_Front;
	std::vector<float> Player::_Right;
	std::vector<float> Player::_Up;

	bool Player::isMouseChanged;
	std::vector<float> Player::mouse_Position;

	float Player::cameraSpeed;
	float Player::sensitivity;

	Player::Player()
	{
		_firstMove = true;
		isPlayerMoved = false;
		player_Position = { 0.0, 0.0, 0.0 };
		_Front = { 0.0, 0.0, 0.0 };
		_Right = { 0.0, 0.0, 0.0 };
		_Up = { 0.0, 0.0, 0.0 };
		isMouseChanged = false;
		mouse_Position = { 0.0, 0.0 };
		cameraSpeed = 1.5f;
		sensitivity = 0.2f;
	}
	Player::~Player()
	{
	}

	bool Player::Get_isMouseChanged()
	{
		return isMouseChanged;
	}
	bool Player::Get_isFirstMove()
	{
		return _firstMove;
	}
	std::vector<float> Player::Get_Front()
	{
		return _Front;
	}
	std::vector<float> Player::Get_Right()
	{
		return _Right;
	}
	std::vector<float> Player::Get_Up()
	{
		return _Up;
	}
	std::vector<float> Player::Get_MousePos()
	{
		return mouse_Position;
	}
	std::vector<float> Player::Get_PlayerPosition()
	{
		return player_Position;
	}
	float Player::Get_CameraSpeed()
	{
		return cameraSpeed;
	}
	float Player::Get_Sensativity()
	{
		return sensitivity;
	}
	void Player::Set_isFirstMove(bool value)
	{
		_firstMove = value;
	}
	void Player::Set_MousePos(std::vector<float> value)
	{
		mouse_Position = value;
	}
	void Player::Set_PlayerPosition(std::vector<float> value)
	{
		player_Position = value;
	}
}