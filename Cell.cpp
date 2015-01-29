#include "Cell.h"

Cell::Cell(){

}

Cell::Cell(int r, int c){
	row = r;
	column = c;
	x = column * CELL_DIMENSION;
	y = row * CELL_DIMENSION;
	state = OFF;
}


Cell::~Cell(){
}

void Cell::turnOn(){
	state = ON;
}

void Cell::turnOff(){
	state = OFF;
}

bool Cell::isOn(){
	return ((state == ON) ? true : false);
}

void Cell::checkState(Cell **c){
	int n = 0;
	if (c[row - 1][column - 1].isOn()) n++;
	if (c[row - 1][column].isOn()) n++;
	if (c[row - 1][column + 1].isOn()) n++;
	if (c[row][column + 1].isOn()) n++;
	if (c[row + 1][column + 1].isOn()) n++;
	if (c[row + 1][column].isOn()) n++;
	if (c[row + 1][column - 1].isOn()) n++;
	if (c[row][column - 1].isOn()) n++;

	if (!isOn() && n == 3) turnOn();
	if (isOn() && (n == 2 || n == 3)) turnOn();
	if (n < 2) turnOff();
	if (n > 3) turnOff();


}

void Cell::draw(){
	al_draw_filled_rectangle(x, y, x + CELL_DIMENSION, y + CELL_DIMENSION, !isOn() ? al_map_rgb(0, 0, 0) : al_map_rgb(255, 255, 255));
}