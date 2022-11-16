#include "raylib.h"

#include "programManager.h"
#include "game/game.h"
#include "menu/mainMenu.h"
#include "menu/credits.h"

#include <iostream>

namespace MoonPatrol {

	ProgramStatus programStatus; // El estado actual del juego.
	bool gameShouldClose; // Para salir del game loop.

	const int screenWidth = 1024;
	const int screenHeight = 768;

	const char* programName = "Moon Patrol";
	const char* programVersion = "0.2";

	static void initRespectiveStatus(ProgramStatus status);
	static void closeProgram();
	static void updateProgram();
	static void initProgram();

	// --

	void initRespectiveStatus(ProgramStatus status) {
		switch (status) {
		case ProgramStatus::INGAME:
			Game::init();
			break;
		case ProgramStatus::MAINMENU:
			MainMenu::init();
			break;
		case ProgramStatus::CREDITS:
			Credits::init();
			break;
		default:
			std::cout << "Invalid program Status! [ProgramManager.cpp - InitRespectiveStatus()]\n";
			break;
		}
	}

	void closeProgram() {
		//Assets::Unload();
		CloseWindow();
	}

	void updateProgram() {
		while (!WindowShouldClose() && !gameShouldClose) {
			switch (programStatus) {
			case ProgramStatus::INGAME:
				Game::update();
				break;
			case ProgramStatus::MAINMENU:
				MainMenu::update();
				break;
			case ProgramStatus::CREDITS:
				Credits::update();
				break;
			default:
				std::cout << "Invalid program Status! [ProgramManager.cpp - UpdateProgram()]\n";
				break;
			}
		}
	}

	void initProgram() {
		InitWindow(screenWidth, screenHeight, programName);
		SetExitKey(KEY_NULL); // No queremos que la ventana se cierre con escape.
		//Assets::Init(); // Cargamos los assets.
		//Settings::InitSettings(); // Se inicializan las settings default cuando se ejecuta el programa.
		setProgramStatus(ProgramStatus::MAINMENU);
	}

	// Global

	const char* getProgramVersion() {
		return programVersion;
	}

	void setGameShouldClose(bool value) {
		gameShouldClose = value;
	}

	void setProgramStatus(ProgramStatus status) {
		initRespectiveStatus(status);
		programStatus = status;
	}

	void startProgram() {
		initProgram();
		updateProgram();
		closeProgram();
	}

}