
#include "vehicle.h"
#include "collisionManager.h"

namespace MoonPatrol {
	namespace Vehicles {

		// Private

		// --

		// Public

		Vehicle create() {
			Vehicle vehicle;
			vehicle.position = { 0, 0 };
			vehicle.size = { 0, 0 };
			vehicle.speed = 0;
			return vehicle;
		}

		void move(Vehicle& vehicle, int direction) {
			if(!Collisions::vehicleWall(vehicle))
				vehicle.position.x += direction * (vehicle.speed * GetFrameTime());
			else {
				if (vehicle.position.x < (GetScreenWidth() * .5f)) {
					vehicle.position.x = (vehicle.size.x * .5f);
				}
				else {
					vehicle.position.x = static_cast<float>(GetScreenWidth() - (vehicle.size.x * .5f));
				}
			}
		}

		void draw(Vehicle vehicle) {
			Rectangle rec = { vehicle.position.x, vehicle.position.y, vehicle.size.x, vehicle.size.y };
			DrawRectanglePro(rec, { (vehicle.size.x * .5f), (vehicle.size.y * .5f) }, 0, RED);
		}

		void update() {
			// Vacio y Ensalada.
		}

		void init(Vehicle& vehicle, float speed) {
			vehicle = create();
			vehicle.position = { static_cast<float>(GetScreenWidth() * .25f), static_cast<float>(GetScreenHeight() * .75f) };
			vehicle.size = { static_cast<float>(GetScreenHeight() * .15f), static_cast<float>(GetScreenHeight() * .15f) };
			vehicle.speed = speed;
		}
	}
}