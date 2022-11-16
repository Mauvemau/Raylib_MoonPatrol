#include "button.h"
#include "utils.h"

namespace MoonPatrol {
	namespace Buttons {
		void centerButton(Button& button);

		// --

		void centerButton(Button& button) {
			button.pos.x -= (button.size.x * .5f);
			button.pos.y -= (button.size.y * .5f);
		}

		// Global

		void hover(Button& button, bool value) {
			button.hovered = value;
		}

		void draw(Button button) {
			if (button.hovered) {
				DrawRectangle(static_cast<int>(button.pos.x), static_cast<int>(button.pos.y), static_cast<int>(button.size.x), static_cast<int>(button.size.y), button.col);
				Utils::DrawCenteredText(button.text,
					Vector2{ static_cast<float>(button.pos.x + (button.size.x * .5)), static_cast<float>(button.pos.y + (button.size.y * .5)) },
					static_cast<int>(button.size.y * .5f), BLACK);
			}
			else {
				DrawRectangleLines(static_cast<int>(button.pos.x), static_cast<int>(button.pos.y), static_cast<int>(button.size.x), static_cast<int>(button.size.y), button.col);
				Utils::DrawCenteredText(button.text,
					Vector2{ static_cast<float>(button.pos.x + (button.size.x * .5)), static_cast<float>(button.pos.y + (button.size.y * .5)) },
					static_cast<int>(button.size.y * .5f), button.col);
			}
		}

		bool update(Button& button) {
			return (button.hovered && IsKeyPressed(KEY_ENTER) || IsKeyPressed(KEY_X));
		}

		Button create(int id, Vector2 pos, Vector2 size) {
			Button button;
			button.id = id;
			button.pos = pos;
			button.size = size;
			button.col = RAYWHITE;
			button.text = "";
			button.hovered = false;
			centerButton(button);
			return button;
		}

		Button create(int id, Vector2 pos, Vector2 size, Color col) {
			Button button;
			button.id = id;
			button.pos = pos;
			button.size = size;
			button.col = col;
			button.text = "";
			button.hovered = false;
			centerButton(button);
			return button;
		}

		Button create(int id, Vector2 pos, Vector2 size, const char* text) {
			Button button;
			button.id = id;
			button.pos = pos;
			button.size = size;
			button.col = RAYWHITE;
			button.text = text;
			button.hovered = false;
			centerButton(button);
			return button;
		}

		Button create(int id, Vector2 pos, Vector2 size, Color col, const char* text) {
			Button button;
			button.id = id;
			button.pos = pos;
			button.size = size;
			button.col = col;
			button.text = text;
			button.hovered = false;
			centerButton(button);
			return button;
		}
	}
}