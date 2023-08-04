#pragma once
class Main
{
public:
	Main();
	~Main();

public:
	void Init(HWND hwnd);
	void Update();
	void Render();

private:
	HWND _hwnd = {};
	HDC _hdc = {};

};

