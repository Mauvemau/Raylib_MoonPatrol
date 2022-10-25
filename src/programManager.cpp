#include "raylib.h"

#include "programManager.h"
#include "game.h"

#include <iostream>

ProgramStatus programStatus; // El estado actual del juego.
bool gameShouldClose; // Para salir del game loop.

const int screenWidth = 1024;
const int screenHeight = 768;

static void InitRespectiveStatus(ProgramStatus status);
static void CloseProgram();
static void UpdateProgram();
static void InitProgram();

// --

void InitRespectiveStatus(ProgramStatus status) {
	switch (status)
	{
	case ProgramStatus::INGAME:
		Game::Init();
		break;
	default:
		std::cout << "Invalid program Status! [ProgramManager.cpp - InitRespectiveStatus()]\n";
		break;
	}
}

void CloseProgram() {
	//Assets::Unload();
	CloseWindow();
}

void UpdateProgram() {
	while (!WindowShouldClose() && !gameShouldClose) {
		switch (programStatus)
		{
		case ProgramStatus::INGAME:
			Game::Update();
			break;
		default:
			std::cout << "Invalid program Status! [ProgramManager.cpp - UpdateProgram()]\n";
			break;
		}
	}
}

void InitProgram() {
	InitWindow(screenWidth, screenHeight, "Raylib Asteroids");
	//SetExitKey(KEY_NULL); // No queremos que la ventana se cierre con escape.
	//Assets::Init(); // Cargamos los assets.
	//Settings::InitSettings(); // Se inicializan las settings default cuando se ejecuta el programa.
	SetProgramStatus(ProgramStatus::INGAME);
}

// Global

void SetGameShouldClose(bool value) {
	gameShouldClose = value;
}

void SetProgramStatus(ProgramStatus status) {
	InitRespectiveStatus(status);
	programStatus = status;
}

void StartProgram() {
	InitProgram();
	UpdateProgram();
	CloseProgram();
}