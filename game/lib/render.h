#ifndef RENDER_H
#include <raylib.h>
#include "map.h"
using namespace std;

void InitScreen();
void drawCellBox(fcord p, Cell& cell);
void drawCellBall(fcord p, Cell& cell);
void renderBox(fcord pos, Color color, float t=2);
void renderEdge(fcord st, fcord ed, float t, Color color);

#define RENDER_H
#endif
