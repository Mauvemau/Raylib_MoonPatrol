#pragma once

#include "raylib.h"

namespace MoonPatrol {
	namespace Weapons {
		struct Weapon {
			float fireRate;
			float firePower;
			float bulletCaliber;
			bool hurtsPlayer;
			
			float lastShot;
		};

		enum class Types {
			GUN, // Un arma normal que dispara hacia arriba.
			RIFLE, // Un arma poderosa que dispara hacia delante.
			COUNT
		};

		Weapon create();

		Weapon createWeaponFromTemplate(Types type);

		void shoot(Weapon& weapon, Vector2 shootPosition, float direction);

		void init(Weapon& weapon, float fireRate, float firePower, float bulletCaliber, bool hurtsPlayer);
	}
}