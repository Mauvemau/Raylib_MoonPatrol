
#include "raylib.h"

namespace MoonPatrol {

	namespace Game {

		// Private

		void draw();

		// --

		void draw() {
			BeginDrawing();
			ClearBackground(BLACK);

			EndDrawing();
		}

		// Public

		void update() {

			draw();
		}

		void init() {

		}
	}

}