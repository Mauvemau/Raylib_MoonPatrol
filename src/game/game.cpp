#include "game.h"
#include "programManager.h"
#include "vehicle.h"
#include "obstacle.h"
#include "inputManager.h"

#include <iostream>
#include <chrono>

using namespace std;

namespace MoonPatrol {
	namespace Game {

		// Private

		Vehicles::Vehicle player;
		Obstacles::Obstacle obstacle;

		chrono::steady_clock::time_point startTime;

		void draw();

		// --

		void draw() {
			BeginDrawing();
			ClearBackground(BLACK);

			DrawRectangle(0, static_cast<int>(GetScreenHeight() * .75f + (player.size.y * .5f)), GetScreenWidth(), static_cast<int>(GetScreenHeight() * .25f - (player.size.y * .5f)), DARKPURPLE);

			Vehicles::draw(player);

			Obstacles::draw(obstacle);

			DrawText(getProgramVersion(), 
				static_cast<int>(GetScreenHeight() * .01f), 
				static_cast<int>(GetScreenHeight() * .01f), 
				static_cast<int>(GetScreenHeight() * .04f), 
				RAYWHITE);

			EndDrawing();
		}

		// Public

		float getTime() {
			float curTime = (static_cast<int>(chrono::duration_cast<chrono::milliseconds>(chrono::steady_clock::now() - startTime).count())) * .001f;
			return curTime;
		}

		void update() {
			Input::update(player);

			Vehicles::update(player);

			Obstacles::update(obstacle, 200.0f);

			draw();
		}

		void init() {
			startTime = chrono::steady_clock::now();
			Vehicles::init(player, 400.0f, (GetScreenHeight() * .2f));
			Obstacles::init(obstacle);
		}

	}
}