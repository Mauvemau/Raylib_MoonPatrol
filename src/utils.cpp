#include "utils.h"

namespace Utils {
    Vector2 LineLineIntersection(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4) {
        Vector2 intersection;

        intersection.x =
            (((x1 * y2 - y1 * x2) * (x3 - x4)) - ((x1 - x2) * (x3 * y4 - y3 * x4))) /
            (((x1 - x2) * (y3 - y4)) - ((y1 - y2) * (x3 - x4)));

        intersection.y =
            (((x1 * y2 - y1 * x2) * (y3 - y4)) - ((y1 - y2) * (x3 * y4 - y3 * x4))) /
            (((x1 - x2) * (y3 - y4)) - ((y1 - y2) * (x3 - x4)));

        return intersection;
    }
	void DrawCenteredText(const char* text, Vector2 pos, int fontSize, Color color) {
		int textWide = MeasureText(text, fontSize);
		DrawText(text, static_cast<int>((pos.x) - (textWide * .5)), static_cast<int>((pos.y) - (fontSize * .5)), fontSize, color);
	}
}