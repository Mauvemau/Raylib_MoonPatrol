#pragma once

#include "raylib.h"

namespace MoonPatrol {
	namespace Terrains {
		struct Node {
			float x;
			float y;
		};

		static const int maxNodes = 20;
		struct Terrain {
			Node nodes[maxNodes];
			int amountNodes; // Cantidad de nodos que se estan usando.
			float padding; // Distancia entre cada nodo.
			float minAltitude;
			float maxAltitude;
			float speed; // La velocidad a la que el terreno se mueve hacia la izquierda.
			Color color;
		};

		Terrain create();

		void draw(Terrain terrain);
		void update(Terrain& terrain);
		void init(Terrain& terrain, float padding, float minAltitude, float maxAltitude, float speed, Color color);
	}
}