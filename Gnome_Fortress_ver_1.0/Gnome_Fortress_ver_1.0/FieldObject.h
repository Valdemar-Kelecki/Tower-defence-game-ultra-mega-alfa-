#pragma once

class FieldObject { // virtual

protected:

	int xPosition;
	int yPosition;

	char illustration;

public:

	FieldObject() {}
	FieldObject(int xPos,int yPos) {
		xPosition = xPos / 32;
		yPosition = yPos / 32;
	}

	char Draw() {
		return illustration;
	}
	virtual int X() = 0 {
		return xPosition;
	}
	virtual int Y() = 0 {
		return yPosition;
	}
};
