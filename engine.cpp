#include <iostream>
#include <allegro5\allegro.h>

#include "World.h"

const int DISPLAY_WIDTH = 1200;
const int DISPLAY_HEIGHT = 800;

int main(){
	ALLEGRO_DISPLAY *display;
	ALLEGRO_TIMER *timer;
	ALLEGRO_EVENT event;
	ALLEGRO_EVENT_QUEUE *eventQueue;

	al_init();
	al_init_primitives_addon();
	al_install_mouse();
	al_install_keyboard();

	display = al_create_display(DISPLAY_WIDTH, DISPLAY_HEIGHT);
	timer = al_create_timer(1 / 15.0);
	eventQueue = al_create_event_queue();

	bool running = true, redraw = true, started = false;
	World world(DISPLAY_WIDTH / CELL_DIMENSION, DISPLAY_HEIGHT / CELL_DIMENSION);


	al_register_event_source(eventQueue, al_get_display_event_source(display));
	al_register_event_source(eventQueue, al_get_timer_event_source(timer));
	al_register_event_source(eventQueue, al_get_mouse_event_source());
	al_register_event_source(eventQueue, al_get_keyboard_event_source());

	al_start_timer(timer);
	while (running){
		al_wait_for_event(eventQueue, &event);
		switch (event.type){
		case ALLEGRO_EVENT_TIMER:
			redraw = true;
			if (started){
				world.checkStates();
			}
			break;
		case ALLEGRO_EVENT_KEY_DOWN:
			if (event.keyboard.keycode == ALLEGRO_KEY_ESCAPE){
				running = false;
				break;
			}
			else if (event.keyboard.keycode == ALLEGRO_KEY_S){
				started = !started;
				break;
			}
			break;
		case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN:
			if (world.cells[event.mouse.y / CELL_DIMENSION][event.mouse.x / CELL_DIMENSION].isOn()) world.cells[event.mouse.y / CELL_DIMENSION][event.mouse.x / CELL_DIMENSION].turnOff();
			else world.cells[event.mouse.y / CELL_DIMENSION][event.mouse.x / CELL_DIMENSION].turnOn();
			break;
		}

		if (redraw){
			redraw = false;
			al_clear_to_color(al_map_rgb(0, 0, 0));
			world.draw();
			al_flip_display();
		}
	}

	al_destroy_display(display);
	al_destroy_timer(timer);
	al_destroy_event_queue(eventQueue);
	
}