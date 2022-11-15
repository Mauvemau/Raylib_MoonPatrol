#include "game.h"
#include "programManager.h"
#include "vehicle.h"
#include "obstacle.h"
#include "inputManager.h"
#include "collisionManager.h"

#include <iostream>
#include <chrono>

using namespace std;

namespace MoonPatrol {
	namespace Game {

		// Private

		Vehicles::Vehicle player;
		Obstacles::Obstacle obstacle;

		chrono::steady_clock::time_point startTime;

		bool paused;
		chrono::steady_clock::time_point pauseStartTime; // En caso del juego estar pausado por determinado tiempo, se lo sumamos al startTime.

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

			if (paused) {
				DrawText("Game Over",
					static_cast<int>(GetScreenWidth() * .05f),
					static_cast<int>(GetScreenHeight() * .4f),
					static_cast<int>(GetScreenHeight() * .08f),
					RED);
				DrawText("Press [R] key to restart",
					static_cast<int>(GetScreenWidth() * .05f),
					static_cast<int>(GetScreenHeight() * .5f),
					static_cast<int>(GetScreenHeight() * .035f),
					RAYWHITE);
			}

			EndDrawing();
		}

		// Public

		void setPaused(bool value) {
			paused = value;
		}

		float getTime() {
			float curTime = (static_cast<int>(chrono::duration_cast<chrono::milliseconds>(chrono::steady_clock::now() - startTime).count())) * .001f;
			return curTime;
		}

		void update() {
			if (!paused) {
				Input::update(player);

				Vehicles::update(player);

				Obstacles::update(obstacle, 200.0f);

				if (Collisions::vehicleObstacle(player, obstacle)) {
					Vehicles::setColor(player, ORANGE);
					setPaused(true);
				}
				else {
					Vehicles::setColor(player, RED);
				}
			}

			if (paused) {
				if (IsKeyPressed(KEY_R))
					setProgramStatus(ProgramStatus::INGAME);
			}

			draw();
		}

		void init() {
			startTime = chrono::steady_clock::now();
			Vehicles::init(player, 400.0f, (GetScreenHeight() * .2f));
			Obstacles::init(obstacle);

			paused = false;
		}

	}
}