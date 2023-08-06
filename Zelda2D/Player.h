#pragma once
#include "FlipbookActor.h"

class BoxCollider;

class Player : public FlipbookActor
{
	using Super = FlipbookActor;

public:
	Player();
	virtual ~Player() override;

	virtual void BeginPlay() override;
	virtual void Tick() override;
	virtual void Render(HDC hdc) override;

	virtual void OnComponentBeginOverlap(Collider* collider, Collider* other) override;
	virtual void OnComponentEndOverlap(Collider* collider, Collider* other) override;

private:
	void TickGravity();

	/* 
	내가 충돌한 만큼 뒤로 밀쳐내서 복원 보정.
	b1 이 나, b2 가 상대방.
	*/
	void AdjustCollisionPos(BoxCollider* b1, BoxCollider* b2); 

private:
	Flipbook* _flipbookUp = nullptr;
	Flipbook* _flipbookDown = nullptr;
	Flipbook* _flipbookLeft = nullptr;
	Flipbook* _flipbookRight = nullptr;
};

