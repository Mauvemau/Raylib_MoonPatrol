
#include "vehicle.h"
#include "collisionManager.h"
#include "game.h"

namespace MoonPatrol {
	namespace Vehicles {

		// Private

		// --

		// Public

		Vehicle create() {
			Vehicle vehicle;
			vehicle.position = { 0, 0 };
			vehicle.size = { 0, 0 };
			vehicle.verticalAcceleration = 0;
			vehicle.speed = 0;
			vehicle.gravity = 0;
			vehicle.jumpForce = 0;
			vehicle.color = RAYWHITE;
			return vehicle;
		}

		void setColor(Vehicle& vehicle, Color color) {
			vehicle.color = color;
		}

		void jump(Vehicle& vehicle) {
			if(vehicle.position.y + vehicle.size.y >= Game::getFloorHeight(0))
			vehicle.verticalAcceleration -= vehicle.jumpForce;
		}

		void move(Vehicle& vehicle, int direction) {
			vehicle.position.x += direction * (vehicle.speed * GetFrameTime());
			if(Collisions::vehicleWall(vehicle)) {
				if (vehicle.position.x < (GetScreenWidth() * .5f)) {
					vehicle.position.x = 0;
				}
				else {
					vehicle.position.x = static_cast<float>(GetScreenWidth() - vehicle.size.x);
				}
			}
		}

		void draw(Vehicle vehicle) {
			DrawRectangle(static_cast<int>(vehicle.position.x), static_cast<int>(vehicle.position.y),
						  static_cast<int>(vehicle.size.x), static_cast<int>(vehicle.size.y), vehicle.color);
		}

		void update(Vehicle& vehicle, float floorLevel) {
			if (vehicle.position.y + vehicle.size.y < floorLevel) {
				vehicle.verticalAcceleration += vehicle.gravity * GetFrameTime();
			}
			if (vehicle.position.y + vehicle.size.y > floorLevel) {
				vehicle.verticalAcceleration = 0;
				vehicle.position.y = floorLevel - vehicle.size.y;
			}

			vehicle.position.y += vehicle.verticalAcceleration;
		}

		void init(Vehicle& vehicle, float speed, float jumpForce, float gravity) {
			vehicle = create();
			vehicle.position = { static_cast<float>(GetScreenWidth() * .2f), static_cast<float>(GetScreenHeight() * .6f) };
			vehicle.size = { static_cast<float>(GetScreenHeight() * .2f), static_cast<float>(GetScreenHeight() * .2f) };
			vehicle.speed = speed;
			vehicle.gravity = gravity;
			vehicle.jumpForce = jumpForce;
			vehicle.color = RED;
		}
	}
}