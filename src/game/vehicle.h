#pragma once
#include "raylib.h"
#include "weapon.h"

namespace MoonPatrol {
	namespace Vehicles {
		static const int amountWeapons = 6;
		struct Vehicle {
			Vector2 position;
			Vector2 size;
			float verticalAcceleration;
			float speed;
			float gravity;
			float jumpForce;
			float heigth; // Separación del piso.
			Color color;
			Weapons::Weapon weapons[amountWeapons];
		};

		Vehicle create();

		void setColor(Vehicle& vehicle, Color color);

		void shoot(Vehicle& vehicle);
		void jump(Vehicle& vehicle);
		void move(Vehicle& vehicle, int direction);

		void draw(Vehicle vehicle);
		void update(Vehicle& vehicle);
		void init(Vehicle& vehicle, Vector2 position, Vector2 size, float speed, float gravity, float jumpForce, float height);
	}
}