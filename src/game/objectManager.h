#pragma once

#include "raylib.h"

namespace MoonPatrol {
	namespace ObjectManager {

		// Getters

		int getActiveEnemies();

		// Pool Controls
		void removeBullet(int id);
		void addBullet(Vector2 position, float radius, float directionAngle, float speed, bool hurtsPlayer);

		void removeEnemy(int id);
		void addEnemy(float center, float hitRadius, float speed, int direction);

		// General 
		void draw();
		void update();
		void init();
	}
}