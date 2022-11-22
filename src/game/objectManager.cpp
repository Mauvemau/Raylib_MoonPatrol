#include "objectManager.h"

// Objects
#include "bullet.h"

namespace MoonPatrol {
	namespace ObjectManager {

		// -- Private

		const int maxBullets = 100;
		Bullets::Bullet bullets[maxBullets];
		int activeBullets;

		// --

		// -- Public

		// Pool Controls
		void removeBullet(int id) {
			if (id < activeBullets) {
				bullets[id] = bullets[activeBullets - 1];
				activeBullets--;
			}
		}

		void addBullet(Vector2 position, float radius, float directionAngle, float speed, bool hurtsPlayer) {
			if (activeBullets < maxBullets) {
				Bullets::init(bullets[activeBullets], position, radius, directionAngle, speed, hurtsPlayer);
				activeBullets++;
			}
		}

		// General 
		void draw() {
			// Bullets
			for (int i = 0; i < activeBullets; i++) {
				Bullets::draw(bullets[i]);
			}

		}

		void update() {
			// Bullets
			for (int i = 0; i < activeBullets; i++) {
				Bullets::update(bullets[i]);
			}

		}

		void init() {
			// Bullets
			for (int i = 0; i < maxBullets; i++) {
				bullets[i] = Bullets::create();
			}
			activeBullets = 0;

		}

	}
}