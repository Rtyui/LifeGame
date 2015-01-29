#pragma once
#include <allegro5\allegro.h>
#include <allegro5\allegro_primitives.h>
#include <iostream>
using namespace std;

enum STATES{ON, OFF};
const int CELL_DIMENSION = 10;

class Cell
{
public:
	int state;
	int row;
	int column;
	float x;
	float y;

	Cell();
	Cell(int r, int c);
	~Cell();
	void turnOn();
	void turnOff();
	bool isOn();
	void checkState(Cell **c);
	void draw();
};
