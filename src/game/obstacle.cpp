#include "obstacle.h"

namespace MoonPatrol {
	namespace Obstacles {

		// Private

		void move(Obstacle& obstacle, float speed, int direction);

		// --

		void move(Obstacle& obstacle, float speed, int direction) {
			obstacle.position.x += direction * (speed * GetFrameTime());
		}

		// Public

		Obstacle create() {
			Obstacle obstacle;
			obstacle.position = { 0, 0 };
			obstacle.size = { 0, 0 };
			return obstacle;
		}

		void draw(Obstacle obstacle) {
			DrawRectangle(static_cast<int>(obstacle.position.x), static_cast<int>(obstacle.position.y), 
						  static_cast<int>(obstacle.size.x), static_cast<int>(obstacle.size.y), GREEN);
		}

		void update(Obstacle& obstacle, float speed) {
			move(obstacle, speed, -1);
			if (obstacle.position.x < (-obstacle.size.x))
				obstacle.position.x = static_cast<float>((GetScreenWidth() * 1) + obstacle.size.x);
		}

		void init(Obstacle& obstacle) {
			obstacle = create();
			obstacle.size = { static_cast<float>(GetScreenHeight() * .1f), static_cast<float>(GetScreenHeight() * .1f) };
			obstacle.position = { static_cast<float>((GetScreenWidth() * 1) + obstacle.size.x) , static_cast<float>(GetScreenHeight() * .725f) };
		}

	}
}