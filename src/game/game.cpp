#include "game.h"
#include "inputManager.h"

namespace MoonPatrol {
	namespace Game {

		// Private

		Vehicles::Vehicle player;

		void draw();

		// --

		void draw() {
			BeginDrawing();
			ClearBackground(BLACK);

			Vehicles::draw(player);

			EndDrawing();
		}

		// Public

		void update() {
			Input::update(player);

			draw();
		}

		void init() {
			Vehicles::init(player, 400.0f);
		}

	}
}