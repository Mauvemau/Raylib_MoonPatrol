#include "inputManager.h"

#include <iostream>

using namespace std;

namespace MoonPatrol {
	namespace Input {

		// Private

		// --

		// Public

		void update(Vehicles::Vehicle& vehicle) {
			if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A)) {
				Vehicles::move(vehicle, -1);
			}
			else if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D)) {
				Vehicles::move(vehicle, +1);
			}
			if (IsKeyPressed(KEY_X) || IsKeyPressed(KEY_SPACE)) {
				Vehicles::jump(vehicle);
			}
			if (IsKeyDown(KEY_Z) || IsKeyDown(KEY_LEFT_CONTROL)) {
				// Handle Shooting
			}
		}
	}
}