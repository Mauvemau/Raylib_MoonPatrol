#pragma once
#include "raylib.h"

namespace MoonPatrol {
	namespace Vehicles {

		struct Vehicle {
			Vector2 position;
			Vector2 size;
			float speed;
		};

		Vehicle create();

		void move(Vehicle& vehicle, int direction);

		void draw(Vehicle vehicle);
		void update();
		void init(Vehicle& vehicle, float speed);
	}
}