#pragma once

#include "raylib.h"

namespace Utils {
	const double m_pi = 3.14159265358979323846;

	float DegreesToRadians(float deg);
	float RadiansToDegrees(float rad);
	Vector2 LineLineIntersection(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4);
	void DrawCenteredText(const char* text, Vector2 pos, int fontSize, Color color);
}