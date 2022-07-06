#pragma once
#include "Map.h"
#include "FieldObject.h"
#include "Enemies.h"

class Towers : public FieldObject { //virtual


protected:

	int damage;
	int attackSpeed;
	int range;
	int level;
	int count; 
	
	Enemies* target = nullptr;
	void FindEnemy(Enemies** enemiesWave, int numberOfEnemies);
public:
	Towers(int xPos, int yPos) : FieldObject(xPos,yPos) {
		target = nullptr;
	};
	virtual int Attack(Enemies** enemiesWave,int numberOfEnemies) = 0;
	int X() {
		return xPosition;
	}
	int Y() {
		return yPosition;
	}
};





class LightTower : public Towers {

public:
	LightTower(int xPos, int yPos) : Towers(xPos,yPos){ 
		damage = 10;
		attackSpeed = 50;
		range = 1;
		count = 0;
		illustration = 'l';
	}
	int Attack(Enemies** enemiesWave, int numberOfEnemies) ;
};



class HeavyTower : public Towers {

public:
	HeavyTower(int xPos, int yPos) : Towers(xPos, yPos) {
		damage = 20;
		attackSpeed = 250;
		range = 3;
		count = 0;
		illustration = 'h';
	}
	int Attack(Enemies** enemiesWave, int numberOfEnemies);
};



class SpecialTower : public Towers {
	  
public:
	SpecialTower(int xPos, int yPos) : Towers(xPos, yPos) { 
		damage = 5;
		attackSpeed = 30;
		range = 2;
		count = 0;
		illustration = 's';
	}
	int Attack(Enemies** enemiesWave, int numberOfEnemies);
};