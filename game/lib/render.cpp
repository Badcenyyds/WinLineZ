#include "render.h"
#include <raymath.h>

void InitScreen() {
	InitWindow(1000, 1000, "LineZ v1.0");
	SetConfigFlags(FLAG_MSAA_4X_HINT);
	SetTargetFPS(120);
}

void drawCellBox(fcord p, Cell& cell) {
	float highlight = cell.highlight.getVal(), iR = cell.innerR.getVal(), iG = cell.innerG.getVal(); 
	float t = 0 + 4 * (1 - highlight), h = 3;
	DrawRectangleV({p.x +t, p.y +t}, {gridsize - 2*t, gridsize - 2*t}, colorMix(BLACK, WHITE, (highlight/2+.5)));
	float ratio = 1 / (1 + iR + iG);
	DrawRectangleV({p.x +t+h, p.y +t+h}, {gridsize -2*(t+h), gridsize -2*(t+h)}, { ratio * iR * 255 + ratio * 80, ratio * iG * 255 + ratio * 80, ratio * 80,  255 });
}

void DrawRoundedRectRotated(fcord _center, float size, float rotation, float roundness, Color color) {
	float halfSize = size;
	float radius = halfSize * roundness;
	int segments = 16; // 每个圆角的细分段数
	Vector2 center(_center.x, _center.y);
	
	// 生成圆角矩形轮廓点
	int totalPoints = segments * 4;
	Vector2 points[totalPoints];
	int pointIndex = 0;
	
	// 生成四个圆角点
	for (int corner = 0; corner < 4; corner++) {
		float cornerAngle = corner * PI / 2.0f;
		Vector2 cornerCenter = {
			((corner + 1) & 2 ? -1 : 1) * (halfSize - radius),
			(corner & 2 ? -1 : 1) * (halfSize - radius)
		};
		
		for (int i = 0; i < segments; i++) {
			float angle = cornerAngle + (i * (PI/2.0f) / (segments-1));
			points[pointIndex].x = cornerCenter.x + cosf(angle) * radius;
			points[pointIndex].y = cornerCenter.y + sinf(angle) * radius;
			pointIndex++;
		}
	}
	
	// 旋转并平移所有点
	for (int i = 0; i < totalPoints; i++) {
		Vector2 rotated = Vector2Rotate(points[i], rotation);
		points[i] = Vector2Add(center, rotated);
	}
	
	// 绘制填充（三角剖分）
	for (int i = 0; i < totalPoints; i++) {
		int next = (i + 1) % totalPoints;
		DrawTriangle(center, points[next], points[i], color);
	}
}

void drawCellBall(fcord p, Cell& cell) {
	Color color = ballColor[cell.type];
	float size = 20 + cell.size.getVal(), shift = cell.shift.getVal(), rotation = cell.rotation.getVal();
	p = p + fcord(gridsize/2, gridsize/2);
	// roundness formula: r2=1+(r1-1)/1.1
	DrawRoundedRectRotated(p + fcord(0, 4), size * 1.2, rotation, .45, {16, 16, 16, 127});
	DrawRoundedRectRotated(p + fcord(0,-2-shift), size * 1.2, rotation, .45, colorMix(color, WHITE, .2));
	DrawRoundedRectRotated(p + fcord(0,-2-shift), size, rotation, .4, colorMix(color, DARKGRAY, .1));
	
//	DrawCircle(p.x + gridsize/2, p.y + gridsize/2+4, size * 1.1, {16, 16, 16, 127});
//	DrawCircle(p.x + gridsize/2, p.y + gridsize/2-2 - shift, size * 1.1, colorMix(color, WHITE, .2));
//	DrawCircle(p.x + gridsize/2, p.y + gridsize/2-2 - shift, size, colorMix(color, DARKGRAY, .2));
}

void renderBox(fcord pos, Color color, float t) {
	DrawRectangleLinesEx({pos.x -t, pos.y -t, gridsize +2*t, gridsize +2*t}, 2*t, color);
}

void renderEdge(fcord st, fcord ed, float t, Color color) {
	DrawLineEx({st.x, st.y}, {ed.x, ed.y}, t, color);
}
