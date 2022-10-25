#pragma once
/*
Maneja los loops y distintas pantallas del juego.
*/

namespace MoonPatrol {
	enum class ProgramStatus {
		INGAME
	};

	void setGameShouldClose(bool value);
	void setProgramStatus(ProgramStatus status);
	void startProgram();
}