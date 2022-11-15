#pragma once

#include "raylib.h"

namespace MoonPatrol {
	namespace Obstacles {
		
		struct Obstacle {
			Vector2 position;
			Vector2 size;
		};

		Obstacle create();

		void draw(Obstacle obstacle);
		void update(Obstacle& obstacle, float speed);
		void init(Obstacle& obstacle);

	}
}