#include "game.h"
#include "programManager.h"
#include "terrain.h"
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

		Terrains::Terrain floor;
		Terrains::Terrain mountainsNear;
		Terrains::Terrain mountainsBack;

		chrono::steady_clock::time_point startTime;

		bool paused;
		chrono::steady_clock::time_point pauseStartTime; // En caso del juego estar pausado por determinado tiempo, se lo sumamos al startTime.

		void draw();

		// --

		void draw() {
			BeginDrawing();
			ClearBackground({ 30, 15, 55, 255 });

			Terrains::draw(mountainsBack);
			Terrains::draw(mountainsNear);
			Terrains::draw(floor);

			Vehicles::draw(player);

			Obstacles::draw(obstacle);

			DrawText(getProgramVersion(), 
				static_cast<int>(GetScreenHeight() * .01f), 
				static_cast<int>(GetScreenHeight() * .01f), 
				static_cast<int>(GetScreenHeight() * .04f), 
				RAYWHITE);

			DrawText("Press [ESC] key to return to the menu",
				static_cast<int>(GetScreenHeight() * .01f),
				static_cast<int>(GetScreenHeight() * .96f),
				static_cast<int>(GetScreenHeight() * .035f),
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

		float getFloorHeight(float xPos) {
			static_cast<void>(xPos);
			return (GetScreenHeight() * .8f);
		}

		void update() {
			if (!paused) {
				Input::update(player);

				Vehicles::update(player, getFloorHeight(0));

				//Obstacles::update(obstacle, 300.0f);

				Terrains::update(floor);
				Terrains::update(mountainsNear);
				Terrains::update(mountainsBack);

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

			Vehicles::init(player, 400.0f, .5f, 1.0f);
			Obstacles::init(obstacle);

			Terrains::init(floor, GetScreenWidth() * .1f, GetScreenHeight() * .85f, GetScreenHeight() * .75f, 300.0f, {230, 180, 80, 255});
			Terrains::init(mountainsNear, GetScreenWidth() * .2f, GetScreenHeight() * .7f, GetScreenHeight() * .5f, 100.0f, { 145, 120, 50, 255 });
			Terrains::init(mountainsBack, GetScreenWidth() * .3f, GetScreenHeight() * .7f, GetScreenHeight() * .4f, 50.0f, { 40, 30, 15, 255 });

			paused = false;
			pauseStartTime = chrono::steady_clock::now();
		}

	}
}