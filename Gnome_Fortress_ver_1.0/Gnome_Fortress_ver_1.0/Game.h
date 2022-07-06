#pragma once
#include <SFML/Graphics.hpp>
#include "Towers.h"
#include "Enemies.h"
#include <string>

using namespace sf;

class Game {

	RenderWindow mainWindow;
	Map mainMap;

	bool isRunning = true;
	int fortressHelth = 30;
	int money = 30;



	int numberOfTowers=0;
	Towers** towerMassiv = nullptr;
	
	int lightTowerCost = 10;
	int heavyTowerCost = 15;
	int specialTowerCost = 15;

	bool readyToBuildLightTower = false;
	bool readyToBuildHeavyTower = false;
	bool readyToBuildSpecialTower = false;

	bool CheckBuildAcces(int xPos,int yPos);
	void Add(Towers* someTowerToAdd);

	int prevPositionX;
	int prevPositionY;
	bool prevRezult = true;

	int xFinish = 44;
	int yFinish = 9;

	int numberOfEnemies=0;
	Enemies** enemiesMassiv = nullptr;
	bool waveGoing = false;
	int waveNumber = 1;
	
	void ResetLeaders();
	void CreateNewWave();
	void ResetWay();
	bool TheyAlive();

	

	struct SpritesPack {
	
		Texture mainTexture;
	
		
		Sprite mapFloor_1;
		Sprite mapFloor_2;
		Sprite mapFloor_3;
		Sprite mapWallNorth;
		Sprite mapWallSouth;
		Sprite mapWallWest;
		Sprite mapWallEast;
		Sprite mapEnemyGate;
		Sprite mapCastleGate;
		Sprite mapAnotherTile;

		Sprite fortressHealth;
		Sprite money;
		Sprite buttonForLightTower;
		Sprite buttonForHeavyTower;
		Sprite buttonForSpecialTower;


		Sprite SuccesLightTowerBuild_1;
		Sprite FailureLightTowerBuild_1;

		Sprite SuccesHeavyTowerBuild_1;
		Sprite FailureHeavyTowerBuild_1;

		Sprite SuccesSpecialTowerBuild_1;
		Sprite FailureSpecialTowerBuild_1;


		Sprite lightTowerLvl_1;
		Sprite lightTowerLvl_2;
		Sprite lightTowerLvl_3;

		Sprite heavyTowerLvl_1;
		Sprite heavyTowerLvl_2;
		Sprite heavyTowerLvl_3;

		Sprite specialTowerLvl_1;
		Sprite specialTowerLvl_2;
		Sprite specialTowerLvl_3;


		Sprite enemyGoblin;
		Sprite enemyOrk;
		Sprite enemyOgre;
		Sprite enemyFlameSpirit;

	} sprites;

	struct TextPack{

		Font font;
		Text text;
	} texts;

public:

	~Game();

	void Initialized();
	bool Running();

	void UserInputs();
	void UpdateWorld();
	void RedrawWorld();

	int* TestFunction() {
		int ms[2];
		ms[0] = prevPositionX;
		ms[1] = prevPositionY;
		return ms; }
};
