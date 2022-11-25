#pragma once

#include "raylib.h"
#include "weapon.h"

namespace MoonPatrol {
	namespace Enemies {
		struct Enemy {
			Vector2 position;
			float yCenter; // Centro del movimiento sinusoidal en y.
			int lives;
			float hitRadius;
			float speed;
			int direction;
			Weapons::Weapon weapon;
		};

		Enemy create();

		void draw(Enemy enemy);
		void update(Enemy& enemy);
		void init(Enemy& enemy, float yCenter, int lives, float hitRadius, float speed, int direction, Weapons::Weapon weapon);
	}
}