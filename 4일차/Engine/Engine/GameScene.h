#pragma once
#include "Scene.h"
#include "Sprite.h"
#include <list>
#include "Animation.h"

class GameScene : public Scene
{
private:
	float gravity;
	bool doubleJump, isJump;

	std::list<Sprite*>backgroundList;
	std::list<Sprite*>bridgeList;
	Animation* player;
public:
	GameScene();
	~GameScene();

	void Render();
	void Update(float dTime);
};

