#include <iostream>
#include "Time.h"
#include "Keyboard.h"
#include "Mouse.h"
#include "Entity.h"
#include "Screen.h"
#include "Sprite.h"
#include "Weapon.h"
#include <stdlib.h>
#include <SDL.h>
#undef main
using namespace std;

bool running = true;
int fps = 0, ups = 0;

Time time;
Screen *screen = new Screen;
Keyboard* keyboard = new Keyboard;
Sprite* redBallS = new Sprite(screen, 100, 300, screen->width / 2, screen->height / 2, "Data/Sprites/redBall.png");
Entity* redBallE = new Entity(redBallS);
Weapon* basicWeapon = new Weapon(redBallS);

void update() {
	redBallE->update();
}

void render() {
	screen->clearScreen();
	basicWeapon->render();
	screen->printScreen();
}

int main(int argc, char* argv[]) {

	redBallE->gravity = 9.82;

	while (running) {

		keyboard->update();
		if (keyboard->esc) return 0;

		//Skriver ut ups och fps
		if (time.runEvery(999, 1)) {
			std::cout << "UPS: " << ups << std::endl << "FPS: " << fps << std::endl << std::endl;
			std::cout << std::endl << "Screen: " << screen->width  << "px, " << screen->height << "px" << std::endl;
			fps = 0;
			ups = 0;
		}

		//Updaterar spelet
		update();
		ups++;

		//Renderar spelet
		render();
		fps++;

	}

	return 0;

}

