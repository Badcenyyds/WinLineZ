#ifndef PARTICAL_H
#define PARTICAL_H
#include "consts.h"
#include "gradient.h"

struct Partical {
	fcord pos;
	gradient<fcord> vel; 
	float size;
	int color;
	float vlen;
	
	void upd() {
		vel.upd();
		pos = pos + vel.getVal();
		size *= .998; 
	}
};

#endif
