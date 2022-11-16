#include "utils.h"

namespace Utils {
	void DrawCenteredText(const char* text, Vector2 pos, int fontSize, Color color) {
		int textWide = MeasureText(text, fontSize);
		DrawText(text, static_cast<int>((pos.x) - (textWide * .5)), static_cast<int>((pos.y) - (fontSize * .5)), fontSize, color);
	}
}