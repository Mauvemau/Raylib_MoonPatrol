
#include "vehicle.h"
#include "collisionManager.h"
#include "game.h"

#include <iostream>

namespace MoonPatrol {
	namespace Vehicles {

		// Private

		bool floored;

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
			vehicle.heigth = 0;
			vehicle.color = RAYWHITE;
			return vehicle;
		}

		void setColor(Vehicle& vehicle, Color color) {
			vehicle.color = color;
		}

		void jump(Vehicle& vehicle) {
			if (floored) {
				floored = false;
				vehicle.verticalAcceleration = -vehicle.jumpForce;
			}
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

		void update(Vehicle& vehicle) {
			float floorElevation = Game::getFloorElevation(vehicle.position.x + (vehicle.size.x * .5f));

			if (vehicle.position.y + vehicle.size.y + vehicle.heigth < floorElevation) {
				vehicle.verticalAcceleration += vehicle.gravity * GetFrameTime();
			}
			if (vehicle.position.y + vehicle.size.y + vehicle.heigth >= floorElevation) {
				if (vehicle.verticalAcceleration > 0) { 
					vehicle.verticalAcceleration = 0;
					floored = true;
				}
				vehicle.position.y = floorElevation - vehicle.size.y - vehicle.heigth;
			}

			vehicle.position.y += vehicle.verticalAcceleration;
		}

		void init(Vehicle& vehicle, Vector2 position, Vector2 size, float speed, float gravity, float jumpForce, float height) {
			vehicle = create();
			vehicle.position = position;
			vehicle.size = size;
			vehicle.position.y -= size.y;
			vehicle.speed = speed;
			vehicle.gravity = gravity;
			vehicle.jumpForce = jumpForce;
			vehicle.heigth = height;
			vehicle.color = RED;

			floored = false;
		}
	}
}