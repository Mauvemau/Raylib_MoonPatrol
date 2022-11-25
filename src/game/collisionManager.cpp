#include "collisionManager.h"

#include <iostream>

namespace MoonPatrol {
	namespace Collisions {

		// Private

		bool rectangleRectangleCollision(Vector2 rec1Pos, Vector2 rec1Size, Vector2 rec2Pos, Vector2 rec2Size);
		bool CircleCircleCollision(Vector2 aPos, float aRadius, Vector2 bPos, float bRadius);


		// --

		bool enemyWall(Enemies::Enemy enemy) {
			return (enemy.position.x < 0 || enemy.position.x > GetScreenWidth());
		}

		bool rectangleRectangleCollision(Vector2 rec1Pos, Vector2 rec1Size, Vector2 rec2Pos, Vector2 rec2Size) {
			return (rec1Pos.x < rec2Pos.x + rec2Size.x &&
					rec1Pos.x + rec1Size.x > rec2Pos.x &&
					rec1Pos.y < rec2Pos.y + rec2Size.y &&
					rec1Size.y + rec1Pos.y > rec2Pos.y);
		}

		bool CircleCircleCollision(Vector2 c1Pos, float c1Radius, Vector2 c2Pos, float c2Radius) {
			float distX = c1Pos.x - c2Pos.x;
			float distY = c1Pos.y - c2Pos.y;
			float dist = sqrtf((distX * distX) + (distY * distY));

			return (dist <= (c1Radius + c2Radius));
		}

		// Public

		bool bulletEnemy(Bullets::Bullet bullet, Enemies::Enemy enemy) {
			return CircleCircleCollision(bullet.position, bullet.radius, enemy.position, enemy.hitRadius);
		}

		bool bulletWall(Bullets::Bullet bullet) {
			return (bullet.position.x - bullet.radius <= 0 || bullet.position.y - bullet.radius <= 0 ||
					bullet.position.x + bullet.radius >= GetScreenWidth() || bullet.position.y + bullet.radius >= GetScreenHeight());
		}

		bool vehicleWall(Vehicles::Vehicle vehicle) {
			return (vehicle.position.x < 0 || (vehicle.position.x + vehicle.size.x) > GetScreenWidth());
		}

		bool vehicleObstacle(Vehicles::Vehicle vehicle, Obstacles::Obstacle obstacle) {
			return (rectangleRectangleCollision(vehicle.position, vehicle.size, obstacle.position, obstacle.size));
		}
	}
}