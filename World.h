#pragma once
#include "Cell.h"
class World
{
public:
	Cell **cells;
	int width;
	int height;

	World(int width, int height);
	~World();

	void checkStates();
	void draw();
};

