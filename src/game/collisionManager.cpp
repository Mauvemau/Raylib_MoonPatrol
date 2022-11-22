#include "collisionManager.h"

namespace MoonPatrol {
	namespace Collisions {

		// Private

		bool rectangleRectangleCollision(Vector2 rec1Pos, Vector2 rec1Size, Vector2 rec2Pos, Vector2 rec2Size);

		// --

		bool rectangleRectangleCollision(Vector2 rec1Pos, Vector2 rec1Size, Vector2 rec2Pos, Vector2 rec2Size) {
			return (rec1Pos.x < rec2Pos.x + rec2Size.x &&
					rec1Pos.x + rec1Size.x > rec2Pos.x &&
					rec1Pos.y < rec2Pos.y + rec2Size.y &&
					rec1Size.y + rec1Pos.y > rec2Pos.y);
		}

		// Public

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