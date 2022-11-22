#pragma once

#include "raylib.h"

namespace MoonPatrol {
	namespace Weapons {
		struct Weapon {
			float fireRate;
			float firePower;
			float bulletCaliber; 
			bool hurtsPlayer;
		};

		Weapon create();

		void shoot(Weapon weapon, Vector2 shootPosition);

		void init(Weapon& weapon, float fireRate, float firePower, float bulletCaliber, bool hurtsPlayer);
	}
}