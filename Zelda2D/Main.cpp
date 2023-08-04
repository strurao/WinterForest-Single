#include "pch.h"
#include "Main.h"
#include "TimeManager.h"
#include "InputManager.h"
#include "SceneManager.h"

Main::Main()
{

}

Main::~Main()
{
	// GET_SINGLE(SceneManager)->Clear();
	// GET_SINGLE(ResourceManager)->Clear();
	GET_SINGLE(SceneManager)->Clear();
	_CrtDumpMemoryLeaks();
}

void Main::Init(HWND hwnd)
{
	_hwnd = hwnd; // 윈도우 번호
	_hdc = ::GetDC(hwnd); // 그리는 도화지의 번호

	GET_SINGLE(TimeManager)->Init();
	GET_SINGLE(InputManager)->Init(hwnd);
	GET_SINGLE(SceneManager)->Init();

	// DEFAULT SCENE 
	GET_SINGLE(SceneManager)->ChangeScene(SceneType::DevScene);
}

void Main::Update()
{
	GET_SINGLE(TimeManager)->Update();
	GET_SINGLE(InputManager)->Update();
	GET_SINGLE(SceneManager)->Update();
}

void Main::Render()
{
	uint32 fps = GET_SINGLE(TimeManager)->GetFPS();
	float deltaTime = GET_SINGLE(TimeManager)->GetDeltaTime();

	{
		POINT mousePos = GET_SINGLE(InputManager)->GetMousePos();
		wstring str = std::format(L"Mouse({0}, {1})", mousePos.x, mousePos.y);
		::TextOut(_hdc, 20, 10, str.c_str(), static_cast<int32>(str.size()));
	}

	{
		wstring str = std::format(L"FPS({0}), DT({1} ms)", fps, static_cast<int32>(deltaTime * 1000));
		::TextOut(_hdc, 650, 10, str.c_str(), static_cast<int32>(str.size()));
	}

	GET_SINGLE(SceneManager)->Render(_hdc);
}
