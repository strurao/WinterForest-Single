#include "pch.h"
#include "Player.h"
#include "InputManager.h"

Player::Player()
{
}

Player::~Player()
{
}

void Player::BeginPlay()
{
	Super::BeginPlay();
}

void Player::Tick()
{
	Super::Tick();

	// TODO
	if(GET_SINGLE(InputManager)->GetButton(KeyType::W))
	{

	}

}

void Player::Render(HDC hdc)
{
	Super::Render(hdc);

}
