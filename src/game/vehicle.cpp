
#include "vehicle.h"

namespace MoonPatrol {
	namespace Vehicles {

		// Private

		// --

		// Public

		Vehicle create() {
			Vehicle vehicle;
			vehicle.position = { 0, 0 };
			vehicle.size = { 0, 0 };
			return vehicle;
		}

		void draw(Vehicle vehicle) {
			Rectangle rec = { vehicle.position.x, vehicle.position.y, vehicle.size.x, vehicle.size.y };
			DrawRectanglePro(rec, { (vehicle.size.x * .5f), (vehicle.size.y * .5f) }, 0, RED);
		}

		void update() {
			// Vacio y Ensalada.
		}

		void init(Vehicle& vehicle) {
			vehicle.position = { static_cast<float>(GetScreenWidth() * .25f), static_cast<float>(GetScreenHeight() * .75f) };
			vehicle.size = { static_cast<float>(GetScreenHeight() * .15f), static_cast<float>(GetScreenHeight() * .15f) };
		}
	}
}