#pragma once
#include "raylib.h"

namespace MoonPatrol {
	namespace Vehicles {

		struct Vehicle {
			Vector2 position;
			Vector2 size;
			float speed;
			float jumpHeight;
			Color color;
		};

		Vehicle create();

		void setColor(Vehicle& vehicle, Color color);

		void jump(Vehicle& vehicle);
		void move(Vehicle& vehicle, int direction);

		void draw(Vehicle vehicle);
		void update(Vehicle& vehicle);
		void init(Vehicle& vehicle, float speed, float jumpHeight);
	}
}