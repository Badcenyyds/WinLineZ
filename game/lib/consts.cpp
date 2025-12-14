#include "consts.h"
#include <random>
#include <raylib.h>

fcord fcord::normalize() { return *this * (1 / hypot(x, y)); }

Color ballColor[] {
	Color{192, 192, 192, 255}, RED, GREEN, BLUE, ORANGE, PINK, BEIGE, SKYBLUE
};

static std::mt19937 _rnd(std::random_device{}());
int rnd(int l, int r) { return _rnd() % (r - l + 1) + l; }
float uniform() { return _rnd() / (1. * _rnd.max()); }
