#pragma once

#include "vehicle.h"

namespace MoonPatrol {
	namespace Game {
		
		void setPaused(bool value);

		float getTime();

		void update();
		void init();
	}
}