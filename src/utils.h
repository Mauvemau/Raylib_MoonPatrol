#pragma once

#include "raylib.h"

namespace Utils {
	Vector2 LineLineIntersection(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4);
	void DrawCenteredText(const char* text, Vector2 pos, int fontSize, Color color);
}