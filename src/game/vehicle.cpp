
#include "vehicle.h"
#include "collisionManager.h"
#include "game.h"

namespace MoonPatrol {
	namespace Vehicles {

		// Private

		static float jumpTime = 1.5f;
		float nextFloor; // Temporal
		bool floored;

		// --

		// Public

		Vehicle create() {
			Vehicle vehicle;
			vehicle.position = { 0, 0 };
			vehicle.size = { 0, 0 };
			vehicle.speed = 0;
			vehicle.jumpHeight = 0;
			return vehicle;
		}

		void jump(Vehicle& vehicle) {
			if (floored) {
				floored = false;
				nextFloor = Game::getTime() + jumpTime;
				vehicle.position.y = vehicle.position.y - vehicle.jumpHeight;
			}
		}

		void move(Vehicle& vehicle, int direction) {
			vehicle.position.x += direction * (vehicle.speed * GetFrameTime());
			if(Collisions::vehicleWall(vehicle)) {
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

		void update(Vehicle& vehicle) {
			if (!floored && Game::getTime() > nextFloor) {
				floored = true;
				vehicle.position.y = static_cast<float>(GetScreenHeight() * .75f);
			}
		}

		void init(Vehicle& vehicle, float speed, float jumpHeight) {
			vehicle = create();
			vehicle.position = { static_cast<float>(GetScreenWidth() * .25f), static_cast<float>(GetScreenHeight() * .75f) };
			vehicle.size = { static_cast<float>(GetScreenHeight() * .15f), static_cast<float>(GetScreenHeight() * .15f) };
			vehicle.speed = speed;
			vehicle.jumpHeight = jumpHeight;

			nextFloor = 0;
			floored = true;
		}
	}
}