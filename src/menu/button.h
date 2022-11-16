#pragma once

#include "raylib.h"

namespace MoonPatrol {
	namespace Buttons {
		struct Button {
			int id;
			Vector2 pos;
			Vector2 size;
			Color col;
			const char* text;
			bool hovered;
		};

		void hover(Button& button, bool value);

		void draw(Button button);
		bool update(Button& button);
		Button create(int id, Vector2 pos, Vector2 size); // Creates a text-less white button.
		Button create(int id, Vector2 pos, Vector2 size, Color col); // Creates a text-less button with custom color.
		Button create(int id, Vector2 pos, Vector2 size, const char* text); // Creates a white button with text.
		Button create(int id, Vector2 pos, Vector2 size, Color col, const char* text); // Creates a button with text and custom color.
	}
}