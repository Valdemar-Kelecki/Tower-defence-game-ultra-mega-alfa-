#pragma once
#include "Map.h"
#include "FieldObject.h"
#include "FindWay.h"

class Enemies : public FieldObject { 
	
protected:

	Way* way = nullptr;
	bool leader;
	int healthPoints;
	int moveSpeed;

	int xPosOnTheWindow;
	int yPosOnTheWindow;

public:
	
	virtual Way* FindWay(int xFinish,int yFinish, Map& mainMap) = 0;
	virtual int SetDamage(int damage, bool specialAttack) = 0;

	Enemies(int xPos,int yPos){
		
		leader = 0;
		xPosition = xPos;
		yPosition = yPos;
		xPosOnTheWindow = xPos * 32;
		yPosOnTheWindow = yPos * 32;
		way = nullptr;
	}

	void SetLeader() { leader = 1; }
	void SetWay(Way& newWay);
	Way& GetWay() { return *way; }

	bool ItsAlive() { return healthPoints > 0; }
	bool ItsLiader() { return leader; }
	bool Move();

	int X() {
		return xPosOnTheWindow;
	}
	int Y(){
		return yPosOnTheWindow;
	}
};




class NormalEnemy : public Enemies {

	void AddNew(std::list<Way>& unknown, std::list<Way>& researched, Map mainMap, Way& way, int x, int y);

protected:
	Way* FindWay(int xFinish, int yFinish, Map& mainMap);
	NormalEnemy(int xPos, int yPos) :Enemies(xPos, yPos) {};
};

class Goblin : public NormalEnemy {

public:
	int SetDamage(int damage, bool specialAttack);
	Goblin(int xPos, int yPos) :NormalEnemy(xPos, yPos) {

		healthPoints = 15;
		moveSpeed = 4;

		illustration = 'g';
	}
};

class Ork : public NormalEnemy {

public:
	int SetDamage(int damage, bool specialAttack);
	Ork(int xPos, int yPos) :NormalEnemy(xPos, yPos) {

		healthPoints = 55;
		moveSpeed = 2;

		illustration = 'o';
	}
};

class Ogre : public NormalEnemy {

public:
	int SetDamage(int damage, bool specialAttack);
	Ogre(int xPos, int yPos) :NormalEnemy(xPos, yPos) {

		healthPoints = 120;
		moveSpeed = 1;

		illustration = 'O';
	}
};


class Spirit : public Enemies {
public:
	Spirit(int xPos, int yPos) :Enemies(xPos, yPos) {

		healthPoints = 25;
		moveSpeed =4;

		illustration = 's';
	}


	Way* FindWay(int xFinish, int yFinish, Map& mainMap);
	int SetDamage(int damage, bool specialAttack);
};