#include "stdafx.h"
#include "GameScene.h"
#include "Background.h"

GameScene::GameScene() {

	score = 0;
	backgroundInstantiate = false;

	//BACKGROUND
	Background* background = new Background();
	background->setPos(0, 0);
	backgroundList.push_back(background);
	AddObject(background);

	//BRIDGE1
	Sprite* tmpBridge = new Sprite("Resources/Image/LoopMap.png");
	tmpBridge->setPos(0, 500);
	bridgeList.push_back(tmpBridge);

	//BRIDGE2
	Sprite* tempBridge = new Sprite("Resources/Image/LoopMap.png");
	tempBridge->setPos(SCREEN_WIDTH, 500);
	bridgeList.push_back(tempBridge);

	//COIN
	Sprite* tmpCoin = new Sprite("Resources/Image/coin-yellow.png");
	tmpCoin->setPos(SCREEN_WIDTH + 70, 400);
	coinList.push_back(tmpCoin);

	//OBSTACLE
	Sprite* tmpObstacle = new Sprite("Resources/Image/Drop.png");
	tmpObstacle->setPos(SCREEN_WIDTH, 400);
	obstacleList.push_back(tmpObstacle);

	for (int i = 0; i < 4; i++) {
		numArray[i].setPos(0 + 60 * i, 10);
	}

	player = new Player();

}
GameScene::~GameScene() {

}
void GameScene::Render() {
	for (auto& background : backgroundList) {
		background->Render();
	}
	for (auto& bridge : bridgeList) {
		bridge->Render();
	}
	for (auto& obstacle : obstacleList) {
		obstacle->Render();
	}
	for (auto& coin : coinList) {
		coin->Render();
	}
	for (int i = 0; i < 4; i++) {
		numArray[i].Render();
	}
	player->Render();
}

void GameScene::Update(float dTime) {
	Scene::Update(dTime);
	player->Update(dTime);
	int diff = 500 * dTime;

	int randNum = rand() % 10 + 1;
	if (randNum == 1) {
		Sprite* tmpCoin = new Sprite("Resources/Image/coin-yellow.png");
		tmpCoin->setPos(SCREEN_WIDTH + 200, 400);
		coinList.push_back(tmpCoin);
	}

	numArray[0].setNum(score / 1000);
	numArray[1].setNum(score / 1000 % 10);
	numArray[2].setNum(score / 10 % 10);
	numArray[3].setNum(score % 10);

	//BACKGROUND
	for (auto iter = backgroundList.begin(); iter != backgroundList.end(); iter++) {

		//(*iter)->Update(dTime);

		if ((*iter)->getPosX() < -SCREEN_WIDTH) {
			RemoveObject((*iter));
			SAFE_DELETE(*iter);
			iter = backgroundList.erase(iter);
			backgroundInstantiate = false;
			if (iter == backgroundList.end()) {
				break;
			}
		}
	}
	if (!backgroundInstantiate) {
		Background* background = new Background();
		background->setPos(SCREEN_WIDTH - 10, 0);
		backgroundList.push_back(background);
		AddObject(background);
		backgroundInstantiate = true;
	}

	//BRIDGE
	for (auto iter = bridgeList.begin(); iter != bridgeList.end(); iter++) {

		(*iter)->setPos((*iter)->getPosX()-diff, (*iter)->getPosY());

		if ((*iter)->getPosX() < -SCREEN_WIDTH) {
			SAFE_DELETE(*iter);
			iter = bridgeList.erase(iter);

			Sprite* tempBridge = new Sprite("Resources/Image/LoopMap.png");
			tempBridge->setPos(SCREEN_WIDTH, 500);
			bridgeList.push_back(tempBridge);

			if (iter == bridgeList.end()) {
				break;
			}
		}
	}

	//OBSTACLE
	for (auto iter = obstacleList.begin(); iter != obstacleList.end(); iter++) {

		(*iter)->setPos((*iter)->getPosX()-diff, (*iter)->getPosY());

		if (player->IsCollisionRect(*iter)) {
			sceneManager->ChangeScene(new MainScene);
			return;
		}

		if ((*iter)->getPosX() < -SCREEN_WIDTH) {
			SAFE_DELETE(*iter);
			iter = obstacleList.erase(iter);

			Sprite* tmpObstacle = new Sprite("Resources/Image/Drop.png");
			tmpObstacle->setPos(SCREEN_WIDTH, 400);
			obstacleList.push_back(tmpObstacle);

			if (iter == obstacleList.end()) {
				break;
			}
		}
	}

	//COIN
	for (auto iter = coinList.begin(); iter != coinList.end(); iter++) {

		(*iter)->setPos((*iter)->getPosX()-diff, (*iter)->getPosY());

		if ((*iter)->getPosX()<-SCREEN_WIDTH) {
			SAFE_DELETE(*iter);
			iter = coinList.erase(iter);

			if (iter == coinList.end()) {
				break;
			}
		}
	}

	//New CoinList
	for (auto iter = coinList.begin(); iter != coinList.end(); iter++) {
		if (player->IsCollisionRect((*iter))) {
			score += 1;
			SAFE_DELETE(*iter);
			iter = coinList.erase(iter);

			if (iter == coinList.end()) {
				break;
			}
		}
	}
}
