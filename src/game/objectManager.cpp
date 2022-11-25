#include "objectManager.h"

#include "collisionManager.h"
#include "game.h"

// Objects
#include "bullet.h"
#include "enemy.h"

#include <iostream>

using namespace std;

namespace MoonPatrol {
	namespace ObjectManager {

		// -- Private

		const int maxBullets = 100;
		Bullets::Bullet bullets[maxBullets];
		int activeBullets;

		const int maxEnemies = 25;
		Enemies::Enemy enemies[maxEnemies];
		int activeEnemies;

		// --

		// -- Public

		// Getters

		int getActiveEnemies() {
			return activeEnemies;
		}

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

		void removeEnemy(int id) {
			if (id < activeEnemies) {
				enemies[id] = enemies[activeEnemies - 1];
				activeEnemies--;
			}
		}

		void addEnemy(float center, float hitRadius, float speed, int direction) {
			if (activeEnemies < maxEnemies) {
				Enemies::init(enemies[activeEnemies], center, 1, hitRadius, speed, direction, Weapons::create());
				activeEnemies++;
			}
		}

		// General 
		void draw() {
			// Bullets
			for (int i = 0; i < activeBullets; i++) {
				Bullets::draw(bullets[i]);
			}
			//Enemies
			for (int i = 0; i < activeEnemies; i++) {
				Enemies::draw(enemies[i]);
			}
		}

		void update() {
			// Bullets
			for (int i = 0; i < activeBullets; i++) {
				Bullets::update(bullets[i]);
				if (Collisions::bulletWall(bullets[i])) {
					removeBullet(i);
				}
				for (int j = 0; j < activeEnemies; j++) {
					if (Collisions::bulletEnemy(bullets[i], enemies[j])) {
						removeEnemy(j);
						Game::setScore(Game::getScore() + 25);
					}
				}
			}
			// Enemies
			for (int i = 0; i < activeEnemies; i++) {
				Enemies::update(enemies[i]);
			}
		}

		void init() {
			// Bullets
			for (int i = 0; i < maxBullets; i++) {
				bullets[i] = Bullets::create();
			}
			activeBullets = 0;

			// Enemies
			for (int i = 0; i < maxEnemies; i++) {
				enemies[i] = Enemies::create();
			}
			activeEnemies = 0;

		}

	}
}