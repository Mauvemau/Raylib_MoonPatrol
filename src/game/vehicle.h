#pragma once
#include "raylib.h"

namespace MoonPatrol {
	namespace Vehicles {

		struct Vehicle {
			Vector2 position;
			Vector2 size;
		};

		Vehicle create();

		void draw(Vehicle vehicle);
		void update();
		void init(Vehicle& vehicle);
	}
}