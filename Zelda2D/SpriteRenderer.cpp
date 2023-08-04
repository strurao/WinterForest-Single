#include "pch.h"
#include "SpriteRenderer.h"
#include "Sprite.h"

void SpriteRenderer::Start()
{
}

void SpriteRenderer::Update()
{
}

void SpriteRenderer::Render(HDC hdc)
{
	if (_sprite == nullptr)
		return;

	Vec2Int size = _sprite->GetSize();

	::BitBlt(hdc,
		0,0,
		size.x,
		size.y,
		_sprite->GetDC(),
		_sprite->GetPos().x,
		_sprite->GetPos().y,
		SRCCOPY);
}
