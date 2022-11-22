#pragma once

#include "raylib.h"

namespace MoonPatrol {
	namespace ObjectManager {

		// Pool Controls
		void removeBullet(int id);
		void addBullet(Vector2 position, float radius, float directionAngle, float speed, bool hurtsPlayer);

		// General 
		void draw();
		void update();
		void init();
	}
}