// GameofLife-origin.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "Game.h"
#include <iostream>

int main()
{
	// Simple Pattern
		 Game *objLifeGame = new Game(4, 4);
		 objLifeGame->ToggleGridCell(1, 1);
		 objLifeGame->ToggleGridCell(1, 2);
		 objLifeGame->ToggleGridCell(2, 1);
		 objLifeGame->ToggleGridCell(2, 2);
		 objLifeGame->ToggleGridCell(2, 3);
		 objLifeGame->ToggleGridCell(3, 3);
		 objLifeGame->MaxGenerations = 4;
		 objLifeGame->Init();

		 ////Toad Pattern 1
		 //Game *objLifeGame = new Game(2, 4);
		 //objLifeGame->ToggleGridCell(0, 1);
		 //objLifeGame->ToggleGridCell(0, 2);
		 //objLifeGame->ToggleGridCell(0, 3);
		 //objLifeGame->ToggleGridCell(1, 0);
		 //objLifeGame->ToggleGridCell(1, 1);
		 //objLifeGame->ToggleGridCell(1, 2);
		 //objLifeGame->MaxGenerations = 8;
		 //objLifeGame->Init();

		 ////Toad Pattern 2
		 //Game *objLifeGame = new Game(4, 2);
		 //objLifeGame->ToggleGridCell(0, 0);
		 //objLifeGame->ToggleGridCell(1, 0);
		 //objLifeGame->ToggleGridCell(1, 1);
		 //objLifeGame->ToggleGridCell(2, 0);
		 //objLifeGame->ToggleGridCell(2, 1);
		 //objLifeGame->ToggleGridCell(3, 1);
		 //objLifeGame->MaxGenerations = 100;
		 //objLifeGame->Init();

		 //Game *objLifeGame = new Game(3, 4);
		 //objLifeGame->ToggleGridCell(0, 1);
		 //objLifeGame->ToggleGridCell(0, 2);
		 //objLifeGame->ToggleGridCell(1, 0);
		 //objLifeGame->ToggleGridCell(1, 3);
		 //objLifeGame->ToggleGridCell(2, 1);
		 //objLifeGame->ToggleGridCell(2, 2);
		 //objLifeGame->MaxGenerations = 20;
		 //objLifeGame->Init();


		 // The Queen Bee Shuttle pattern
		 //Game *objLifeGame = new Game(7, 4);
		 //objLifeGame->ToggleGridCell(0, 0);
		 //objLifeGame->ToggleGridCell(0, 1);
		 //objLifeGame->ToggleGridCell(1, 2);
		 //objLifeGame->ToggleGridCell(2, 3);
		 //objLifeGame->ToggleGridCell(3, 3);
		 //objLifeGame->ToggleGridCell(4, 3);
		 //objLifeGame->ToggleGridCell(5, 2);
		 //objLifeGame->ToggleGridCell(6, 0);
		 //objLifeGame->ToggleGridCell(6, 1);
		 //objLifeGame->MaxGenerations = 100;
		 //objLifeGame->Init();

		 // The Period 3 Oscillator pattern
		 //Game *objLifeGame = new Game(5, 3);
		 //objLifeGame->ToggleGridCell(0, 1);
		 //objLifeGame->ToggleGridCell(1, 0);
		 //objLifeGame->ToggleGridCell(1, 1);
		 //objLifeGame->ToggleGridCell(1, 2);
		 //objLifeGame->ToggleGridCell(2, 0);
		 //objLifeGame->ToggleGridCell(2, 2);
		 //objLifeGame->ToggleGridCell(3, 0);
		 //objLifeGame->ToggleGridCell(3, 1);
		 //objLifeGame->ToggleGridCell(3, 2);
		 //objLifeGame->ToggleGridCell(4, 1);
		 //objLifeGame->MaxGenerations = 50;
		 //objLifeGame->Init();


		 // The period-15 oscillator pattern
	//Game *objLifeGame = new Game(1, 10);
	//objLifeGame->ToggleGridCell(0, 0);
	//objLifeGame->ToggleGridCell(0, 1);
	//objLifeGame->ToggleGridCell(0, 2);
	//objLifeGame->ToggleGridCell(0, 3);
	//objLifeGame->ToggleGridCell(0, 4);
	//objLifeGame->ToggleGridCell(0, 5);
	//objLifeGame->ToggleGridCell(0, 6);
	//objLifeGame->ToggleGridCell(0, 7);
	//objLifeGame->ToggleGridCell(0, 8);
	//objLifeGame->ToggleGridCell(0, 9);
	//objLifeGame->MaxGenerations = 50;
	//objLifeGame->Init();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
