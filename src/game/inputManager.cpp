#include "inputManager.h"

namespace MoonPatrol {
	namespace Input {

		// Private

		void manageVehicleInput(Vehicles::Vehicle vehicle);

		// --

		void manageVehicleInput(Vehicles::Vehicle vehicle) {
			static_cast<void>(vehicle);
			if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A)) {
				// Move Left
			}
			if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D)) {
				// Move Right
			}
			if (IsKeyPressed(KEY_X) || IsKeyPressed(KEY_SPACE)) {
				// Handle Jump
			}
			if (IsKeyDown(KEY_Z) || IsKeyDown(KEY_LEFT_CONTROL)) {
				// Handle Shooting
			}
		}

		// Public

		void update(Vehicles::Vehicle vehicle) {
			manageVehicleInput(vehicle);
		}
	}
}