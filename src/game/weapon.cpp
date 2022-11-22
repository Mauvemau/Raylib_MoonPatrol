#include "weapon.h"

#include "objectManager.h"

namespace MoonPatrol {
	namespace Weapons {

		// Private

		// --

		// Public

		Weapon create() {
			Weapon weapon;
			weapon.fireRate = 0;
			weapon.firePower = 0;
			weapon.bulletCaliber = 0;
			weapon.hurtsPlayer = 0;
			return weapon;
		}

		void shoot(Weapon weapon, Vector2 shootPosition) {
			ObjectManager::addBullet(shootPosition, weapon.bulletCaliber, 0.0f, weapon.firePower, weapon.hurtsPlayer);
		}

		void init(Weapon& weapon, float fireRate, float firePower, float bulletCaliber, bool hurtsPlayer) {
			weapon = create();
			weapon.fireRate = fireRate;
			weapon.firePower = firePower;
			weapon.bulletCaliber = bulletCaliber;
			weapon.hurtsPlayer = hurtsPlayer;
		}
	}
}