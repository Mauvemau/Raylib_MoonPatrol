#pragma once

#include "raylib.h"

namespace MoonPatrol {
	namespace Bullets {
		struct Bullet {
			Vector2 position;
			float radius;
			float directionAngle;
			float speed;
			bool hurtsPlayer;
		};
	
		Bullet create();

		void draw(Bullet bullet);
		void update(Bullet& bullet);
		void init(Bullet& bullet, Vector2 position, float radius, float directionAngle, float speed, bool hurtsPlayer);

	}
}