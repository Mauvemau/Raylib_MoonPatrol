#pragma once

#include "vehicle.h"
#include "obstacle.h"
#include "bullet.h"

namespace MoonPatrol {
	namespace Collisions {
		bool bulletWall(Bullets::Bullet bullet);
		bool vehicleWall(Vehicles::Vehicle vehicle);
		bool vehicleObstacle(Vehicles::Vehicle vehicle, Obstacles::Obstacle obstacle);
	}
}