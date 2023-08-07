#pragma once
#include "FlipbookActor.h"

class Flipbook;
class Collider;
class BoxCollider;

enum class PlayerState
{
	Idle,
	Move,
	Skill
};

class Player : public FlipbookActor
{
	using Super = FlipbookActor;

public:
	Player();
	virtual ~Player() override;

	virtual void BeginPlay() override;
	virtual void Tick() override;
	virtual void Render(HDC hdc) override;

	// virtual void OnComponentBeginOverlap(Collider* collider, Collider* other) override;
	// virtual void OnComponentEndOverlap(Collider* collider, Collider* other) override;

	PlayerState GetState() { return _state; }

private:
	virtual void TickIdle();
	virtual void TickMove();
	virtual void TickSkill();

	void SetState(PlayerState state);
	void SetDir(Dir dir);

	void UpdateAnimation();

	bool HasReachedDest();
	bool CanGo(Vec2Int cellPos);
	void SetCellPos(Vec2Int cellPos, bool teleport = false);

private:
	/*
	내가 충돌한 만큼 뒤로 밀쳐내서 복원 보정.
	b1 이 나, b2 가 상대방.
	*/
	// void AdjustCollisionPos(BoxCollider* b1, BoxCollider* b2);

private:

	Flipbook* _flipbookIdle[4] = {};
	Flipbook* _flipbookMove[4] = {};
	Flipbook* _flipbookAttack[4] = {};

	Vec2Int _cellPos = {};
	Vec2 _speed = {};
	Dir _dir = DIR_DOWN;
	PlayerState _state = PlayerState::Idle;
	bool _keyPressed = false;
};