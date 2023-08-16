#include "pch.h"
#include "Monster.h"
#include "ResourceManager.h"
#include "InputManager.h"
#include "TimeManager.h"
#include "Flipbook.h"
#include "SceneManager.h"
#include "DevScene.h"

Monster::Monster()
{
	_flipbookMove[DIR_UP] = GET_SINGLE(ResourceManager)->GetFlipbook(L"FB_SnakeUp");
	_flipbookMove[DIR_DOWN] = GET_SINGLE(ResourceManager)->GetFlipbook(L"FB_SnakeDown");
	_flipbookMove[DIR_LEFT] = GET_SINGLE(ResourceManager)->GetFlipbook(L"FB_SnakeLeft");
	_flipbookMove[DIR_RIGHT] = GET_SINGLE(ResourceManager)->GetFlipbook(L"FB_SnakeRight");

	_stat.hp = 50;
	_stat.maxHp = 50;
	_stat.attack = 10;
	_stat.defence = 0;
}

Monster::~Monster()
{

}

void Monster::BeginPlay()
{
	Super::BeginPlay();
	SetState(ObjectState::Move);
	SetState(ObjectState::Idle);
}

void Monster::Tick()
{
	Super::Tick();
}

void Monster::Render(HDC hdc)
{
	Super::Render(hdc);
}

void Monster::TickIdle()
{
}

void Monster::TickMove()
{
}

void Monster::TickSkill()
{
}

void Monster::UpdateAnimation()
{
	SetFlipbook(_flipbookMove[_dir]);
}
