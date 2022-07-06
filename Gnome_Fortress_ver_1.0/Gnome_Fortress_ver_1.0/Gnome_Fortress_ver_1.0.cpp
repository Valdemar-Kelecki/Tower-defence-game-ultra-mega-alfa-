#include <iostream>
#include "Game.h"

int main() {

	Game ourGame;
	ourGame.Initialized();

	while (ourGame.Running()) {

		ourGame.UpdateWorld();
		ourGame.UserInputs();
		ourGame.RedrawWorld();

		system("CLS");
		std::cout<<ourGame.TestFunction()[0] << "\t\t" << ourGame.TestFunction()[1] << "\nSprite = " << sizeof(Sprite) << "\nTexture = " << sizeof(Texture);
	}

	system("pause");
	return 0;
}