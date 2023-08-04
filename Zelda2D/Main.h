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

private:
	// DOUBLE BUFFERING
	RECT _rect;
	HDC _hdcBack = {}; // Back Buffer
	HBITMAP _bmpBack = {}; 
};

