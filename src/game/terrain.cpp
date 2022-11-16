#include "terrain.h"

#include <iostream>

namespace MoonPatrol {
	namespace Terrains {

		// Private

		void replaceNode(Terrain& terrain); // Remueve el primer nodo en el array, corre todos los nodos, y añade uno nuevo al final.
		void move(Terrain& terrain); // Mueve los nodos hacia la izquierda.

		// --

		void replaceNode(Terrain& terrain) {
			float min = -terrain.padding * 2;
			for (int i = 1; i < terrain.amountNodes; i++) {
				terrain.nodes[i - 1] = terrain.nodes[i];
			}
			terrain.nodes[terrain.amountNodes - 1].x = min + (terrain.amountNodes * terrain.padding);
			terrain.nodes[terrain.amountNodes - 1].y = static_cast<float>(GetRandomValue(static_cast<int>(terrain.minAltitude), static_cast<int>(terrain.maxAltitude)));
		}

		void move(Terrain& terrain) {
			for (int i = 0; i < terrain.amountNodes; i++) {
				terrain.nodes[i].x += -(terrain.speed * GetFrameTime());
			}
		}

		// Public

		Terrain create() {
			Terrain terrain;
			for (int i = 0; i < maxNodes; i++) {
				terrain.nodes[i] = { 0, 0 };
			}
			terrain.amountNodes = 0;
			terrain.padding = 0;
			terrain.minAltitude = 0;
			terrain.maxAltitude = 0;
			terrain.speed = 0;
			terrain.color = WHITE;
			return terrain;
		}

		void draw(Terrain terrain) {
			for (int i = 0; i < terrain.amountNodes; i++) {
				if (i > 0) {
					int lowest = 0;
					int highest = 0;
					if (terrain.nodes[i - 1].y > terrain.nodes[i].y) {
						lowest = i - 1;
						highest = i;
					}
					else if (terrain.nodes[i - 1].y < terrain.nodes[i].y) {
						lowest = i;
						highest = i - 1;
					}
					else {
						lowest = i;
						highest = i;
					}
					DrawTriangle({ terrain.nodes[highest].x - 2, terrain.nodes[highest].y },
								 { terrain.nodes[lowest].x + 2, terrain.nodes[lowest].y },
								 { terrain.nodes[highest].x - 2, terrain.nodes[lowest].y }, terrain.color);
					DrawTriangle({ terrain.nodes[highest].x - 2, terrain.nodes[highest].y },
								 { terrain.nodes[highest].x - 2, terrain.nodes[lowest].y },
								 { terrain.nodes[lowest].x + 2, terrain.nodes[lowest].y }, terrain.color);
					DrawRectangle(static_cast<int>(terrain.nodes[i - 1].x) - 2, static_cast<int>(terrain.nodes[lowest].y), 
								  static_cast<int>(terrain.nodes[i].x - terrain.nodes[i - 1].x) + 2, 
								  static_cast<int>(GetScreenHeight() - terrain.nodes[lowest].y), terrain.color);
				}
			}
		}

		void update(Terrain& terrain) {
			float min = -terrain.padding * 2;
			move(terrain);
			if (terrain.nodes[0].x <= min) {
				replaceNode(terrain);
			}
		}

		void init(Terrain& terrain, float padding, float minAltitude, float maxAltitude, float speed, Color color) {
			terrain = create();
			terrain.padding = padding;
			terrain.minAltitude = minAltitude;
			terrain.maxAltitude = maxAltitude;
			terrain.speed = speed;
			terrain.color = color;
			float min = -terrain.padding * 2;
			float max = GetScreenWidth() + (terrain.padding * 2); // Generamos 2 nodos de mas a la derecha por fuera de la pantalla.

			for (int i = 0; i < maxNodes; i++) {
				terrain.nodes[i].x = min + (i * terrain.padding);
				terrain.nodes[i].y = static_cast<float>(GetRandomValue(static_cast<int>(terrain.minAltitude), static_cast<int>(terrain.maxAltitude)));
				terrain.amountNodes = i;
				if (terrain.nodes[i].x >= max) i = maxNodes;
			}
		}
	}
}