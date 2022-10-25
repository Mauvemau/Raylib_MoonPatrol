
#include "raylib.h"

namespace Game {

	// Private

	void Draw();

	// --

	void Draw() {
		BeginDrawing();
		ClearBackground(BLACK);

		EndDrawing();
	}

	// Public

	void Update() {
		
		Draw();
	}

	void Init() {

	}
}