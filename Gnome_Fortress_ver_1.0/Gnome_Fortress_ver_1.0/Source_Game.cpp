#include "Game.h"
Game::~Game() {

	for (int i = 0; i < numberOfTowers; i++)
		delete towerMassiv[i];
	delete towerMassiv;

	for (int i = 0; i < numberOfEnemies; i++)
		delete enemiesMassiv[i];
	delete enemiesMassiv;

	mainWindow.close();
}

void Game::Initialized() {

	sprites.mainTexture.loadFromFile("Tiles/Tileset for TD.png");
	
	sprites.mapFloor_1.setTexture(sprites.mainTexture);
	sprites.mapFloor_2.setTexture(sprites.mainTexture);
	sprites.mapFloor_3.setTexture(sprites.mainTexture);
	sprites.mapWallNorth.setTexture(sprites.mainTexture);
	sprites.mapWallSouth.setTexture(sprites.mainTexture);
	sprites.mapWallWest.setTexture(sprites.mainTexture);
	sprites.mapWallEast.setTexture(sprites.mainTexture);
	sprites.mapEnemyGate.setTexture(sprites.mainTexture);
	sprites.mapCastleGate.setTexture(sprites.mainTexture);
	sprites.mapAnotherTile.setTexture(sprites.mainTexture);

	sprites.fortressHealth.setTexture(sprites.mainTexture);
	sprites.money.setTexture(sprites.mainTexture);
	sprites.buttonForLightTower.setTexture(sprites.mainTexture);
	sprites.buttonForHeavyTower.setTexture(sprites.mainTexture);
	sprites.buttonForSpecialTower.setTexture(sprites.mainTexture);

	sprites.SuccesLightTowerBuild_1.setTexture(sprites.mainTexture);
	sprites.FailureLightTowerBuild_1.setTexture(sprites.mainTexture);


	sprites.SuccesHeavyTowerBuild_1.setTexture(sprites.mainTexture);
	sprites.FailureHeavyTowerBuild_1.setTexture(sprites.mainTexture);


	sprites.SuccesSpecialTowerBuild_1.setTexture(sprites.mainTexture);
	sprites.FailureSpecialTowerBuild_1.setTexture(sprites.mainTexture);

	sprites.lightTowerLvl_1.setTexture(sprites.mainTexture);
	sprites.lightTowerLvl_2.setTexture(sprites.mainTexture);
	sprites.lightTowerLvl_3.setTexture(sprites.mainTexture);

	sprites.heavyTowerLvl_1.setTexture(sprites.mainTexture);
	sprites.heavyTowerLvl_2.setTexture(sprites.mainTexture);
	sprites.heavyTowerLvl_3.setTexture(sprites.mainTexture);

	sprites.specialTowerLvl_1.setTexture(sprites.mainTexture);
	sprites.specialTowerLvl_2.setTexture(sprites.mainTexture);
	sprites.specialTowerLvl_3.setTexture(sprites.mainTexture);

	sprites.enemyGoblin.setTexture(sprites.mainTexture);
	sprites.enemyOrk.setTexture(sprites.mainTexture);
	sprites.enemyOgre.setTexture(sprites.mainTexture);
	sprites.enemyFlameSpirit.setTexture(sprites.mainTexture);


	sprites.mapFloor_1.setTextureRect(IntRect(64, 0, 32, 32));
	sprites.mapFloor_2.setTextureRect(IntRect(96, 0, 32, 32));
	sprites.mapFloor_3.setTextureRect(IntRect(128, 0, 32, 32));
	sprites.mapWallNorth.setTextureRect(IntRect(0, 0, 32, 32));
	sprites.mapWallSouth.setTextureRect(IntRect(32, 0, 32, 32));
	sprites.mapWallWest.setTextureRect(IntRect(32, 64, 32, 32));
	sprites.mapWallEast.setTextureRect(IntRect(0, 64, 32, 32));
	sprites.mapEnemyGate.setTextureRect(IntRect(0, 128, 32, 32));
	sprites.mapCastleGate.setTextureRect(IntRect(0, 128, 32, 32));
	sprites.mapAnotherTile.setTextureRect(IntRect(0,160,32,32));

	sprites.fortressHealth.setTextureRect(IntRect(0, 224, 32, 32));
	sprites.money.setTextureRect(IntRect(0, 192, 32, 32));
	sprites.buttonForLightTower.setTextureRect(IntRect(0, 256, 32, 32));
	sprites.buttonForHeavyTower.setTextureRect(IntRect(32, 256, 32, 32));
	sprites.buttonForSpecialTower.setTextureRect(IntRect(64, 256, 32, 32));

	sprites.SuccesLightTowerBuild_1.setTextureRect(IntRect(0, 288, 32, 32));
	sprites.SuccesLightTowerBuild_1.setColor(Color::Color(0,255,0,100));
	
	sprites.FailureLightTowerBuild_1.setTextureRect(IntRect(0, 288, 32, 32));
	sprites.FailureLightTowerBuild_1.setColor(Color::Color(255, 0, 0, 100));


	sprites.SuccesHeavyTowerBuild_1.setTextureRect(IntRect(32, 288, 32, 32));
	sprites.SuccesHeavyTowerBuild_1.setColor(Color::Color(0, 255, 0, 100));

	sprites.FailureHeavyTowerBuild_1.setTextureRect(IntRect(32, 288, 32, 32));
	sprites.FailureHeavyTowerBuild_1.setColor(Color::Color(255, 0, 0, 100));

	sprites.SuccesSpecialTowerBuild_1.setTextureRect(IntRect(64, 288, 32, 32));
	sprites.SuccesSpecialTowerBuild_1.setColor(Color::Color(0, 255, 0, 100));

	sprites.FailureSpecialTowerBuild_1.setTextureRect(IntRect(64, 288, 32, 32));
	sprites.FailureSpecialTowerBuild_1.setColor(Color::Color(255, 0, 0, 100));


	sprites.lightTowerLvl_1.setTextureRect(IntRect(0, 288, 32, 32));
	sprites.lightTowerLvl_2.setTextureRect(IntRect(0, 0, 0, 0));
	sprites.lightTowerLvl_3.setTextureRect(IntRect(0, 0, 0, 0));

	sprites.heavyTowerLvl_1.setTextureRect(IntRect(32, 288, 32, 32));
	sprites.heavyTowerLvl_2.setTextureRect(IntRect(0, 0, 0, 0));
	sprites.heavyTowerLvl_3.setTextureRect(IntRect(0, 0, 0, 0));

	sprites.specialTowerLvl_1.setTextureRect(IntRect(64, 288, 32, 32));
	sprites.specialTowerLvl_2.setTextureRect(IntRect(0, 0, 0, 0));
	sprites.specialTowerLvl_3.setTextureRect(IntRect(0, 0, 0, 0));

	sprites.enemyGoblin.setTextureRect(IntRect(32, 224, 32, 32));
	sprites.enemyOrk.setTextureRect(IntRect(32, 160, 32, 32));
	sprites.enemyOgre.setTextureRect(IntRect(32, 192, 32, 32));
	sprites.enemyFlameSpirit.setTextureRect(IntRect(32, 128, 32, 32));


	texts.font.loadFromFile("CyrilicOld.ttf");
	
	texts.text.setFont(texts.font);
	texts.text.setCharacterSize(20);

	mainWindow.create(VideoMode(1440, 800), "Gnome fortress ver_1.0");

	prevPositionX = Mouse::getPosition().x / 32;
	prevPositionY = Mouse::getPosition().y / 32;

	CreateNewWave();
}
bool Game::Running() {
	return isRunning;
}

void  Game::UserInputs() {
	Event mainEvent;

	while (mainWindow.pollEvent(mainEvent))
	{
		if (mainEvent.type == Event::Closed)
			isRunning = false;
		if (mainEvent.type == Event::KeyPressed) {
			if (mainEvent.key.code == Keyboard::G)
				money += 100;
			if (mainEvent.key.code == Keyboard::H)
				fortressHelth += 5;
			if (mainEvent.key.code == Keyboard::S && !waveGoing)
				waveGoing = 1;
			if(mainEvent.key.code == Keyboard::Escape)
				isRunning = false;
		}
		if (mainEvent.type == Event::MouseButtonPressed) {
			if (mainEvent.mouseButton.button == Mouse::Left) {
				switch (mainMap.field[mainEvent.mouseButton.y / 32][mainEvent.mouseButton.x / 32]) {
				case 't': break;
				case 'l':
					readyToBuildLightTower = true;
					readyToBuildHeavyTower = false;
					readyToBuildSpecialTower = false;
					break;
				case 'H':
					readyToBuildLightTower = false;
					readyToBuildHeavyTower = true;
					readyToBuildSpecialTower = false;
					break;
				case 's':
					readyToBuildLightTower = false;
					readyToBuildHeavyTower = false;
					readyToBuildSpecialTower = true;
					break;
				default:
					if (readyToBuildLightTower /*&& CheckBuildAcces(mainEvent.mouseButton.x, mainEvent.mouseButton.y)*/ && money >= lightTowerCost) {
						mainMap.field[mainEvent.mouseButton.y / 32][mainEvent.mouseButton.x / 32] = 't';
						Add(new LightTower(mainEvent.mouseButton.x, mainEvent.mouseButton.y));
						money -= lightTowerCost;
						ResetWay();
					}
					else if (readyToBuildHeavyTower /*&& CheckBuildAcces(mainEvent.mouseButton.x, mainEvent.mouseButton.y)*/ && money >= heavyTowerCost) {
						mainMap.field[mainEvent.mouseButton.y / 32][mainEvent.mouseButton.x / 32] = 't';
						Add(new HeavyTower(mainEvent.mouseButton.x, mainEvent.mouseButton.y));
						money -= heavyTowerCost;
						ResetWay();
					}
					else if (readyToBuildSpecialTower /*&& CheckBuildAcces(mainEvent.mouseButton.x, mainEvent.mouseButton.y)*/ && money >= specialTowerCost) {
						mainMap.field[mainEvent.mouseButton.y / 32][mainEvent.mouseButton.x / 32] = 't';
						Add(new SpecialTower(mainEvent.mouseButton.x, mainEvent.mouseButton.y));
						money -= specialTowerCost;
						ResetWay();
					}
				}
			}
			else if (mainEvent.mouseButton.button == Mouse::Right) {
				readyToBuildLightTower = false;
				readyToBuildHeavyTower = false;
				readyToBuildSpecialTower = false;
			}
		}
	}
}

void Game::ResetLeaders() {

	char buf;
		for(int i=0;i<numberOfEnemies;i++)
			if (enemiesMassiv[i]->ItsLiader() && !enemiesMassiv[i]->ItsAlive()) {
				while (!enemiesMassiv[i]->ItsAlive())
					if (++i == numberOfEnemies) return;
			
				enemiesMassiv[i]->SetLeader();
			}
}

void Game::ResetWay() {
	
	for (int i = 0; i < numberOfEnemies; i++)
		if (enemiesMassiv[i]->ItsAlive()) {

			if (enemiesMassiv[i]->ItsLiader())
				enemiesMassiv[i]->SetWay(*(enemiesMassiv[i]->FindWay(xFinish, yFinish, mainMap)));
			else {

				int j = i - 1;
				while (j && !enemiesMassiv[j]->ItsAlive()) j--;

				enemiesMassiv[i]->SetWay(enemiesMassiv[j]->GetWay());
			}
		}
}

bool Game::TheyAlive() {

	int i = 0;
	for (i; i < numberOfEnemies; i++)
		if (enemiesMassiv[i]->ItsAlive())
			return 1;

	return 0;
}

void Game::UpdateWorld() {

	if (waveGoing) {

		for (int i = 0; i < numberOfTowers; i++)
			money+=towerMassiv[i]->Attack(enemiesMassiv,numberOfEnemies);

		if (!TheyAlive()) {
			waveGoing = 0;
			waveNumber++;

			CreateNewWave();
			return;
		}
		ResetLeaders();

		for (int i = 0; i < numberOfEnemies; i++)
			if (enemiesMassiv[i]->Move())
				if (!(--fortressHelth)) {
					isRunning = 0;
					return;
				}
	}
}
void Game::RedrawWorld() {

	mainWindow.clear();

	for (int i = 0; i < mainMap.yHeigth; i++)
		for (int j = 0; j < mainMap.xHeigth; j++) {

			switch (mainMap.field[i][j]) {

			case '.': sprites.mapWallNorth.setPosition(j * 32, i * 32); mainWindow.draw(sprites.mapWallNorth); break;
			case '_': sprites.mapWallSouth.setPosition(j * 32, i * 32);  mainWindow.draw(sprites.mapWallSouth); break;
			case '|': sprites.mapWallEast.setPosition(j * 32, i * 32); mainWindow.draw(sprites.mapWallEast); break;
			case '/': sprites.mapWallWest.setPosition(j * 32, i * 32);  mainWindow.draw(sprites.mapWallWest); break;
			case '-': sprites.mapAnotherTile.setPosition(j * 32, i * 32); mainWindow.draw(sprites.mapAnotherTile); break;
			case 'c': sprites.money.setPosition(j * 32, i * 32); mainWindow.draw(sprites.money); break;
			case 'h': sprites.fortressHealth.setPosition(j * 32, i * 32); mainWindow.draw(sprites.fortressHealth); break;
			case 'l': sprites.buttonForLightTower.setPosition(j * 32, i * 32);  mainWindow.draw(sprites.buttonForLightTower); break;
			case 'H': sprites.buttonForHeavyTower.setPosition(j * 32, i * 32);  mainWindow.draw(sprites.buttonForHeavyTower); break;
			case 's': sprites.buttonForSpecialTower.setPosition(j * 32, i * 32);  mainWindow.draw(sprites.buttonForSpecialTower); break;
			default:  sprites.mapFloor_1.setPosition(j * 32, i * 32); mainWindow.draw(sprites.mapFloor_1);
			}
		}

	for(int i=0;i<numberOfTowers;i++)
		switch (towerMassiv[i]->Draw()) {

		case 'l': sprites.lightTowerLvl_1.setPosition(towerMassiv[i]->X()*32, towerMassiv[i]->Y() * 32); mainWindow.draw(sprites.lightTowerLvl_1); break;
		case 'h': sprites.heavyTowerLvl_1.setPosition(towerMassiv[i]->X()*32, towerMassiv[i]->Y() * 32); mainWindow.draw(sprites.heavyTowerLvl_1); break;
		case 's': sprites.specialTowerLvl_1.setPosition(towerMassiv[i]->X() * 32, towerMassiv[i]->Y() * 32); mainWindow.draw(sprites.specialTowerLvl_1); break;
		}

	for (int i = 0; i < numberOfEnemies; i++) {
		if (enemiesMassiv[i]->ItsAlive())
			switch (enemiesMassiv[i]->Draw()) {

			case 'g': sprites.enemyGoblin.setPosition(enemiesMassiv[i]->X(), enemiesMassiv[i]->Y())      ; mainWindow.draw(sprites.enemyGoblin)      ; break;
			case 'o': sprites.enemyOrk.setPosition(enemiesMassiv[i]->X()   , enemiesMassiv[i]->Y())      ; mainWindow.draw(sprites.enemyOrk)         ; break;
			case 'O': sprites.enemyOgre.setPosition(enemiesMassiv[i]->X()  , enemiesMassiv[i]->Y())      ; mainWindow.draw(sprites.enemyOgre)        ; break;
			case 's': sprites.enemyFlameSpirit.setPosition(enemiesMassiv[i]->X(), enemiesMassiv[i]->Y()) ; mainWindow.draw(sprites.enemyFlameSpirit) ; break;
			}
	}

	if (readyToBuildLightTower)
		switch (CheckBuildAcces(Mouse::getPosition(mainWindow).x, Mouse::getPosition(mainWindow).y)) {

		case true: sprites.SuccesLightTowerBuild_1.setPosition((int)Mouse::getPosition(mainWindow).x / 32 * 32, (int)Mouse::getPosition(mainWindow).y / 32 * 32); mainWindow.draw(sprites.SuccesLightTowerBuild_1); break;
		case false:  
			sprites.FailureLightTowerBuild_1.setPosition((int)Mouse::getPosition(mainWindow).x / 32 * 32, (int)Mouse::getPosition(mainWindow).y / 32 * 32);
			mainWindow.draw(sprites.FailureLightTowerBuild_1); break;
		}
	else if (readyToBuildHeavyTower)
		switch (CheckBuildAcces(Mouse::getPosition(mainWindow).x, Mouse::getPosition(mainWindow).y)) {

		case true: sprites.SuccesHeavyTowerBuild_1.setPosition((int)Mouse::getPosition(mainWindow).x / 32 * 32, (int)Mouse::getPosition(mainWindow).y / 32 * 32); mainWindow.draw(sprites.SuccesHeavyTowerBuild_1); break;
		case false:
			sprites.FailureHeavyTowerBuild_1.setPosition((int)Mouse::getPosition(mainWindow).x / 32 * 32, (int)Mouse::getPosition(mainWindow).y / 32 * 32);
			mainWindow.draw(sprites.FailureHeavyTowerBuild_1); break;
		}
	else if(readyToBuildSpecialTower)
		switch (CheckBuildAcces(Mouse::getPosition(mainWindow).x, Mouse::getPosition(mainWindow).y)) {

		case true: sprites.SuccesSpecialTowerBuild_1.setPosition((int)Mouse::getPosition(mainWindow).x / 32 * 32, (int)Mouse::getPosition(mainWindow).y / 32 * 32); mainWindow.draw(sprites.SuccesSpecialTowerBuild_1); break;
		case false:  sprites.FailureSpecialTowerBuild_1.setPosition((int)Mouse::getPosition(mainWindow).x / 32 * 32, (int)Mouse::getPosition(mainWindow).y / 32 * 32); mainWindow.draw(sprites.FailureSpecialTowerBuild_1); break;
		}

	texts.text.setString(std::to_string(money));
	texts.text.setPosition(96, 5);
	mainWindow.draw(texts.text);

	texts.text.setString("Волна - " + std::to_string(waveNumber));
	texts.text.setPosition/*(250,5);*/(650, 5);
	mainWindow.draw(texts.text);

	texts.text.setString(std::to_string(fortressHelth));
	texts.text.setPosition(1376, 5);
	mainWindow.draw(texts.text);

	mainWindow.display();
}

void Game::Add(Towers* someTowerToAdd) {

	if (!towerMassiv) {

		towerMassiv = new Towers*;
		*towerMassiv = someTowerToAdd;
		numberOfTowers = 1;
	}
	else {
		Towers** buf = new Towers * [++numberOfTowers];

		for (int i = 0; i < numberOfTowers; i++)
			buf[i] = towerMassiv[i];

		buf[numberOfTowers - 1] = someTowerToAdd;
		delete towerMassiv;
		towerMassiv = buf;
	}
}

bool Game::CheckBuildAcces(int xPos, int yPos) {


	if (Mouse::getPosition().x <= mainWindow.getPosition().x || Mouse::getPosition().x >= mainWindow.getPosition().x + mainWindow.getSize().x ||
		Mouse::getPosition().y <= mainWindow.getPosition().y || Mouse::getPosition().y >= mainWindow.getPosition().y + mainWindow.getSize().y) {
		
		prevRezult = false;
		return 0;

	}
	xPos /= 32;
	yPos /= 32;
	
	if (yPos < 0 || mainMap.field[yPos][xPos] != ' ') {
		
		prevRezult = false;
		return 0;
	}
	for (int i = 0; i < numberOfEnemies; i++)
		if (enemiesMassiv[i]->X() / 32 == xPos && enemiesMassiv[i]->Y() / 32 == yPos) {

			prevRezult = false;
			return 0;
		}

	char buf = mainMap.field[yPos][xPos];
	mainMap.field[yPos][xPos] = 't';
	
	if (prevPositionX != Mouse::getPosition().x / 32 ||
		prevPositionY != Mouse::getPosition().y / 32) {


		prevPositionX = Mouse::getPosition().x / 32;
		prevPositionY = Mouse::getPosition().y / 32;

		for (int i = 0; i < numberOfEnemies; i++)
			if (enemiesMassiv[i]->ItsLiader() && !enemiesMassiv[i]->FindWay(xFinish, yFinish, mainMap)) {
				mainMap.field[yPos][xPos] = buf;
				prevRezult = false;
				return 0;
			}
	
		prevRezult = true;
	}

	mainMap.field[yPos][xPos] = buf;
	return prevRezult;
}

void Game::CreateNewWave() {

	if (enemiesMassiv) delete[] enemiesMassiv;

	numberOfEnemies = waveNumber * 3;
	enemiesMassiv = new Enemies * [numberOfEnemies];


	int goblinNumber = rand() % numberOfEnemies + 1;
	int orkNumber = rand() % (numberOfEnemies + 1 - goblinNumber);
	int ogreNumber = rand() % (numberOfEnemies + 1 - goblinNumber - orkNumber);

	for (int i = 0; i < goblinNumber; i++) {
		enemiesMassiv[i] = new Goblin(1 - i, 9);

		if (i == 0) {
			enemiesMassiv[i]->SetLeader();
			enemiesMassiv[i]->SetWay(*(enemiesMassiv[i]->FindWay(xFinish, yFinish, mainMap)));
		}
		else enemiesMassiv[i]->SetWay(enemiesMassiv[i - 1]->GetWay());
	}

	for (int i = goblinNumber; i < orkNumber + goblinNumber; i++) {
		enemiesMassiv[i] = new Ork(1 - i, 9);

		if (i == goblinNumber) {
			enemiesMassiv[i]->SetLeader();
			enemiesMassiv[i]->SetWay(*(enemiesMassiv[i]->FindWay(xFinish, yFinish, mainMap)));
		}
		else
			enemiesMassiv[i]->SetWay(enemiesMassiv[i - 1]->GetWay());
	}

	for (int i = orkNumber + goblinNumber; i < ogreNumber + goblinNumber + orkNumber; i++) {
		enemiesMassiv[i] = new Ogre(1 - i, 9);

		if (i == orkNumber + goblinNumber) {
			enemiesMassiv[i]->SetLeader();
			enemiesMassiv[i]->SetWay(*(enemiesMassiv[i]->FindWay(xFinish, yFinish, mainMap)));
		}
		else
			enemiesMassiv[i]->SetWay(enemiesMassiv[i - 1]->GetWay());
	}


	for (int i = ogreNumber + orkNumber + goblinNumber; i < numberOfEnemies; i++) {
		enemiesMassiv[i] = new Spirit(0 - i, 9);

		if (i == ogreNumber + orkNumber + goblinNumber) {
			enemiesMassiv[i]->SetLeader();
			enemiesMassiv[i]->SetWay(*(enemiesMassiv[i]->FindWay(xFinish, yFinish, mainMap)));
		}
		else
			enemiesMassiv[i]->SetWay(enemiesMassiv[i - 1]->GetWay());
	}

}