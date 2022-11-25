#pragma once

#include "vehicle.h"
#include "obstacle.h"
#include "bullet.h"
#include "enemy.h"

namespace MoonPatrol {
	namespace Collisions {
		bool enemyWall(Enemies::Enemy enemy);
		bool bulletEnemy(Bullets::Bullet bullet, Enemies::Enemy enemy);
		bool bulletWall(Bullets::Bullet bullet);
		bool vehicleWall(Vehicles::Vehicle vehicle);
		bool vehicleObstacle(Vehicles::Vehicle vehicle, Obstacles::Obstacle obstacle);
	}
}