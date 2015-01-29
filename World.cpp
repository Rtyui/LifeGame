#include "World.h"


World::World(int w, int h){
	width = w;
	height = h;
	cells = new Cell*[height];
	for (int i = 0; i < height; i++){
		cells[i] = new Cell[width];
		for (int j = 0; j < width; j++){
			cells[i][j] = Cell(i, j);
		}
	}
}

World::~World(){
}

void World::checkStates(){
	Cell **c;
	c = new Cell*[height];
	for (int i = 0; i < height; i++){
		c[i] = new Cell[width];
		for (int j = 0; j < width; j++){
			c[i][j] = cells[i][j];
		}
	}
	for (int i = 1; i < height - 1; i++){
		for (int j = 1; j < width - 1; j++){
			cells[i][j].checkState(c);
		}
	}
}

void World::draw(){
	for (int i = 0; i < height; i++){
		for (int j = 0; j < width; j++){
			cells[i][j].draw();
		}
	}
}