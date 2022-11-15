#pragma once

#include "vehicle.h"
#include "obstacle.h"

namespace MoonPatrol {
	namespace Collisions {
		bool vehicleWall(Vehicles::Vehicle vehicle);
		bool vehicleObstacle(Vehicles::Vehicle vehicle, Obstacles::Obstacle obstacle);
	}
}