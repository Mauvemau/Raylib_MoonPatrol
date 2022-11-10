#include "collisionManager.h"

namespace MoonPatrol {
	namespace Collisions {
		bool vehicleWall(Vehicles::Vehicle vehicle) {
			return ((vehicle.position.x - (vehicle.size.x * .5f)) < 0 || (vehicle.position.x + (vehicle.size.x * .5f)) > GetScreenWidth());
		}
	}
}