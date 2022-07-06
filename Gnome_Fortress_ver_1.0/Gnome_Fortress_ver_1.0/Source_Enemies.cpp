#include "Enemies.h"

bool Enemies::Move() {
	
	if (!ItsAlive()) return 0;

	while (xPosition == way->X() && yPosition == way->Y()) {
		way = way->Next();

		if (!way) { 
			healthPoints = 0;
			return 1;
		}
	}

	if (xPosition < way->X()) {
		xPosOnTheWindow += moveSpeed;

		if(xPosOnTheWindow / 32 >= way->X())
			xPosition = xPosOnTheWindow / 32;
	}
	else if (xPosition > way->X()) {
		xPosOnTheWindow -= moveSpeed;
	
		if (xPosOnTheWindow / 32 <= way->X() - 1)
			xPosition = xPosOnTheWindow / 32 + 1;
	}
	else if (yPosition < way->Y()) {
		yPosOnTheWindow += moveSpeed;

		if (yPosOnTheWindow / 32 >= way->Y())
			yPosition = yPosOnTheWindow / 32;
	}
	else if (yPosition > way->Y()) {
		yPosOnTheWindow -= moveSpeed;

		if (yPosOnTheWindow / 32 <= way->Y() - 1)
			yPosition = yPosOnTheWindow / 32 + 1;
	}

	return 0;
}

void Enemies::SetWay(Way& newWay) {

	if (leader)
		way = &newWay;
	else {
		way = new Way(xPosition, yPosition);
		way->Add(&newWay);
	}
}

Way* NormalEnemy::FindWay(int xFinish, int yFinish, Map& mainMap) {

	std::list<Way> unknown;
	std::list<Way> researched;

	unknown.push_back(*(new Way(xFinish, yFinish)));

	while (1) {

		if (unknown.empty())
			return nullptr;
		if (xPosition)
			if (unknown.front().X() == xPosition && unknown.front().Y() == yPosition)
				break;
			else
				if (unknown.front().X() == 0 && unknown.front().Y() == yPosition)
					break;

		AddNew(unknown, researched, mainMap, unknown.front(), unknown.front().X() + 1, unknown.front().Y());
		AddNew(unknown, researched, mainMap, unknown.front(), unknown.front().X(), unknown.front().Y() + 1);
		AddNew(unknown, researched, mainMap, unknown.front(), unknown.front().X() - 1, unknown.front().Y());
		AddNew(unknown, researched, mainMap, unknown.front(), unknown.front().X(), unknown.front().Y() - 1);

		researched.splice(researched.begin(), unknown, unknown.begin());

		unknown.sort();
	}

	Way* step = &unknown.front();
	Way* needWay = new Way(step->X(), step->Y());
	Way* buf = needWay;

	step = step->Next();
	while (step) {

		Way* a = new Way(step->X(), step->Y());
		buf->Add(a);
		buf = buf->Next();
		step = step->Next();
	}

	return needWay;
}

void NormalEnemy::AddNew(std::list<Way>& unknown, std::list<Way>& researched, Map mainMap, Way& way, int x, int y) {

	if ( x<mainMap.xHeigth && x >= 0 && y<mainMap.yHeigth && y>0 && mainMap.field[y][x]  == ' ' || x < mainMap.xHeigth && x >= 0 && y < mainMap.yHeigth && y>0 && mainMap.field[y][x] == '0') {

		for (Way& var : researched)
			if (var.X() == x && var.Y() == y) return;
		for (Way& var : unknown)
			if (var.X() == x && var.Y() == y) return;

		unknown.push_back(*(new Way(way, x, y)));
	}
}

Way* Spirit::FindWay(int xFinish, int yFinish, Map& mainMap) {

	Way* needWay = new Way(xPosition, yPosition);
	Way* buf = needWay;
	
	for (int x = xPosition - 1; x != xFinish; x++) {

		Way* a = new Way(x, yPosition);
		buf->Add(a);
		buf = buf->Next();
	}
	return needWay;
}
int Spirit::SetDamage(int damage, bool specialAttack) {

	if (rand() % 2 || specialAttack)
		if ((healthPoints -= damage)<0)	return 15;
		else return 0;
}

int Goblin::SetDamage(int damage, bool specialAttack) {

	if((healthPoints -= damage)<0)
		return 5;
	else return 0;
}

int Ork::SetDamage(int damage, bool specialAttack) {

	if (rand() % 10)
		if ((healthPoints -= damage)<0)
			return 10;
		else return 0;
}

int Ogre::SetDamage(int damage, bool specialAttack) {

	if ((healthPoints -= damage / 2 + specialAttack * damage / 2)<0) return 25;
	else return 0;
}