#pragma once

#include "vehicle.h"

namespace MoonPatrol {
	namespace Game {
		
		void setPaused(bool value);

		float getTime();
		float getFloorHeight(float xPos);

		void update();
		void init();
	}
}