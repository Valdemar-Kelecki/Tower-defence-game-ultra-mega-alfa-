#pragma once
#include <algorithm>
#include <list>


class Way {

	int weight;
	Way* ptrOnPrev;
	int x, y;

public:

	Way(Way& father, int xPos, int yPos) {
		weight = father.weight + 1;
		ptrOnPrev = &father;

		x = xPos;
		y = yPos;
	};
	Way(int xPos, int yPos) {

		weight = 0;
		ptrOnPrev = nullptr;

		x = xPos;
		y = yPos;
	}

	void Add(Way* a) {
		ptrOnPrev = a;
	}

	Way* Next() {
		return ptrOnPrev;
	}
	int X() { return x; }
	int Y() { return y; }


	bool operator < (Way& b) {
		return weight < b.weight;
	}
	bool operator > (Way b) {
		return weight > b.weight;
	}
	bool operator ==(Way b) {
		return x == b.x && y == b.y;
	}
};