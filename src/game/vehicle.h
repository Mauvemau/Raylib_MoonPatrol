#pragma once
#include "raylib.h"

namespace MoonPatrol {
	namespace Vehicles {

		struct Vehicle {
			Vector2 position;
			Vector2 size;
			float verticalAcceleration;
			float speed;
			float gravity;
			float jumpForce;
			Color color;
		};

		Vehicle create();

		void setColor(Vehicle& vehicle, Color color);

		void jump(Vehicle& vehicle);
		void move(Vehicle& vehicle, int direction);

		void draw(Vehicle vehicle);
		void update(Vehicle& vehicle, float floorLevel);
		void init(Vehicle& vehicle, float speed, float jumpForce, float gravity);
	}
}