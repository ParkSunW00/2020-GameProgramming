#include "stdafx.h"
#include "Sprite.h"

Sprite::Sprite(char * path) {
	texture = textureManager->LoadTextureFromFile(path);

	D3DSURFACE_DESC desc;
	texture->GetLevelDesc(0, &desc);

	width = desc.Width;
	height = desc.Height;

	visibleRect.right = 0;
	visibleRect.left = 0;
	visibleRect.top = 0;
	visibleRect.bottom = height;

	rect = visibleRect;

	color = D3DCOLOR_ARGB(255, 255, 255, 255);
}
Sprite::~Sprite() {

}
void Sprite::Render() {
	Object::Render();

	pd3dSprite->SetTransform(&mat);
	pd3dSprite->Draw(texture, &visibleRect, NULL, NULL, color);
}
void Sprite::setCenter(int width, int height, Sprite* sprite) {
	rect.right = width / 2;
	rect.left = -width / 2;
	rect.top = -height / 2;
	rect.bottom = height / 2;

	sprite->pos = D3DXVECTOR2(-width / 2, -height / 2);
}
int Sprite::getHeight() {
	return height;
}
int Sprite::getWidth() {
	return width;
}
D3DCOLOR Sprite::getcolor() {
	return color;
}
void Sprite::setColor(D3DCOLOR color) {
	this->color = color;
}
