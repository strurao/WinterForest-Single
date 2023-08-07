#include "pch.h"
#include "DevScene.h"
#include "Utils.h"
#include "InputManager.h"
#include "TimeManager.h"
#include "ResourceManager.h"
#include "Texture.h"
#include "Values.h"
#include "Actor.h"
#include "SpriteActor.h"
#include "Sprite.h"
#include "Player.h"
#include "Flipbook.h"
#include "BoxCollider.h"
#include "SphereCollider.h"
#include "CollisionManager.h"
#include "UI.h"
#include "TilemapActor.h"
#include "Tilemap.h"
#include "SoundManager.h"
#include "Sound.h"

DevScene::DevScene()
{
}

DevScene::~DevScene()
{
}

void DevScene::Init()
{
	GET_SINGLE(ResourceManager)->LoadTexture(L"Stage01", L"Sprite\\Map\\Stage01.bmp");
	GET_SINGLE(ResourceManager)->LoadTexture(L"Tile", L"Sprite\\Map\\Tile.bmp", RGB(128, 128, 128));
	GET_SINGLE(ResourceManager)->LoadTexture(L"Potion", L"Sprite\\UI\\Mp.bmp");
	GET_SINGLE(ResourceManager)->LoadTexture(L"PlayerDown", L"Sprite\\Player\\PlayerDown.bmp", RGB(128, 128, 128));
	GET_SINGLE(ResourceManager)->LoadTexture(L"PlayerUp", L"Sprite\\Player\\PlayerUp.bmp", RGB(128, 128, 128));
	GET_SINGLE(ResourceManager)->LoadTexture(L"PlayerLeft", L"Sprite\\Player\\PlayerLeft.bmp", RGB(128, 128, 128));
	GET_SINGLE(ResourceManager)->LoadTexture(L"PlayerRight", L"Sprite\\Player\\PlayerRight.bmp", RGB(128, 128, 128));
	GET_SINGLE(ResourceManager)->LoadTexture(L"Start", L"Sprite\\UI\\Start.bmp");
	GET_SINGLE(ResourceManager)->LoadTexture(L"Edit", L"Sprite\\UI\\Edit.bmp");
	GET_SINGLE(ResourceManager)->LoadTexture(L"Exit", L"Sprite\\UI\\Exit.bmp");

	GET_SINGLE(ResourceManager)->CreateSprite(L"Stage01", GET_SINGLE(ResourceManager)->GetTexture(L"Stage01"));
	GET_SINGLE(ResourceManager)->CreateSprite(L"TileO", GET_SINGLE(ResourceManager)->GetTexture(L"Tile"), 0, 0, 48, 48);
	GET_SINGLE(ResourceManager)->CreateSprite(L"TileX", GET_SINGLE(ResourceManager)->GetTexture(L"Tile"), 48, 0, 48, 48);

	GET_SINGLE(ResourceManager)->CreateSprite(L"Start_Off", GET_SINGLE(ResourceManager)->GetTexture(L"Start"), 0, 0, 150, 150);
	GET_SINGLE(ResourceManager)->CreateSprite(L"Start_On", GET_SINGLE(ResourceManager)->GetTexture(L"Start"), 150, 0, 150, 150);
	GET_SINGLE(ResourceManager)->CreateSprite(L"Edit_Off", GET_SINGLE(ResourceManager)->GetTexture(L"Edit"), 0, 0, 150, 150);
	GET_SINGLE(ResourceManager)->CreateSprite(L"Edit_On", GET_SINGLE(ResourceManager)->GetTexture(L"Edit"), 150, 0, 150, 150);
	GET_SINGLE(ResourceManager)->CreateSprite(L"Exit_Off", GET_SINGLE(ResourceManager)->GetTexture(L"Exit"), 0, 0, 150, 150);
	GET_SINGLE(ResourceManager)->CreateSprite(L"Exit_On", GET_SINGLE(ResourceManager)->GetTexture(L"Exit"), 150, 0, 150, 150);

	{
		Texture* texture = GET_SINGLE(ResourceManager)->GetTexture(L"PlayerUp");
		Flipbook* fb = GET_SINGLE(ResourceManager)->CreateFlipbook(L"FB_MoveUp");
		fb->SetInfo({ texture, L"FB_MoveUp", {200, 200}, 0,9,1,0.5f });
	}
	{
		Texture* texture = GET_SINGLE(ResourceManager)->GetTexture(L"PlayerDown");
		Flipbook* fb = GET_SINGLE(ResourceManager)->CreateFlipbook(L"FB_MoveDown");
		fb->SetInfo({ texture, L"FB_MoveDown", {200, 200}, 0,9,1,0.5f });
	}
	{
		Texture* texture = GET_SINGLE(ResourceManager)->GetTexture(L"PlayerLeft");
		Flipbook* fb = GET_SINGLE(ResourceManager)->CreateFlipbook(L"FB_MoveLeft");
		fb->SetInfo({ texture, L"FB_MoveLeft", {200, 200}, 0,9,1,0.5f });
	}
	{
		Texture* texture = GET_SINGLE(ResourceManager)->GetTexture(L"PlayerRight");
		Flipbook* fb = GET_SINGLE(ResourceManager)->CreateFlipbook(L"FB_MoveRight");
		fb->SetInfo({ texture, L"FB_MoveRight", {200, 200}, 0,9,1,0.5f });
	}

	{
		Sprite* sprite = GET_SINGLE(ResourceManager)->GetSprite(L"Stage01");
		SpriteActor* background = new SpriteActor();
		background->SetSprite(sprite);
		background->SetLayer(LAYER_BACKGROUND);
		const Vec2Int size = sprite->GetSize();
		background->SetPos(Vec2(size.x / 2, size.y / 2));
		AddActor(background);
	}

	{
		{
			///* 충돌 기능 
			Player* player = new Player();
			player->SetPos({ 100,100 });

			BoxCollider* collider = new BoxCollider();
			collider->SetSize({ 100,100 });
			
			collider->SetCollisionLayer(CLT_OBJECT);
			collider->ResetCollisionFlag(); // reset
			collider->AddCollisionFlagLayer(CLT_GROUND);
			// collider->AddCollisionFlagLayer(CLT_OBJECT);
			GET_SINGLE(CollisionManager)->AddCollider(collider);
			player->AddComponent(collider);

			AddActor(player);
			//*/
		}
	}

	{
		{
			///* 충돌 기능 테스트 
			Actor* test = new Actor();
			test->SetLayer(LAYER_OBJECT);

			test->SetPos({ 300,200 });
			BoxCollider* collider = new BoxCollider();
			collider->SetSize({ 100,100 });

			/*
			충돌 레이어
			bit flag 연산자 : << >> & | ~
			헷갈린다면 계산기를 키고 그림을 그리기
			
			uint32 flag = 26; 
			// 특정 비트 켜기
			flag = flag | (1 << CLT_WALL); 
			// 특정 비트 끄기
			flag = flag & ~(1 << CLT_WALL); 
			// 특정 비트 체크
			bool ret = flag & (1 << CLT_WALL);
			// 전체 켜기
			flag = ~0; 
			*/

			collider->SetCollisionLayer(CLT_OBJECT);
			GET_SINGLE(CollisionManager)->AddCollider(collider);
			test->AddComponent(collider);

			AddActor(test);
			//*/
		}

		{
			///* 충돌 기능 테스트 
			Actor* test = new Actor();
			test->SetLayer(LAYER_OBJECT);

			test->SetPos({ 200,400 });
			BoxCollider* collider = new BoxCollider();
			collider->SetSize({ 10000,100 });

			collider->SetCollisionLayer(CLT_GROUND);
			//collider->SetCollisionFlag(1 << CLT_WALL);
			GET_SINGLE(CollisionManager)->AddCollider(collider);
			test->AddComponent(collider);

			AddActor(test);
			//*/
		}
	}

	{
		TilemapActor* actor = new TilemapActor();
		AddActor(actor);
		_tilemapActor = actor;
		{
			auto* tm = GET_SINGLE(ResourceManager)->CreateTilemap(L"Tilemap_01");
			tm->SetMapSize({ 63, 43 });
			tm->SetTileSize(48);

			_tilemapActor->SetTilemap(tm);
			// _tilemapActor->SetShowDebug(true);
		}

	}

	GET_SINGLE(ResourceManager)->LoadSound(L"BGM", L"Sound\\BGM.wav");
	{
		Sound* sound = GET_SINGLE(ResourceManager)->GetSound(L"BGM");
		// sound->Play(true);

		// GET_SINGLE(SoundManager)->Play(L"BGM");
	}


	Super::Init();
}

void DevScene::Update()
{
	Super::Update();

	float deltaTime = GET_SINGLE(TimeManager)->GetDeltaTime();

	if (GET_SINGLE(InputManager)->GetButtonDown(KeyType::Q))
	{
		GET_SINGLE(ResourceManager)->SaveTilemap(L"Tilemap_01", L"Tilemap\\Tilemap01.txt");
	}
	else if (GET_SINGLE(InputManager)->GetButtonDown(KeyType::E))
	{
		GET_SINGLE(ResourceManager)->LoadTilemap(L"Tilemap_01", L"Tilemap\\Tilemap01.txt");
	}
}

void DevScene::Render(HDC hdc)
{
	Super::Render(hdc);
}


