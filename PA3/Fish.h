#ifndef FISH_H
#define FISH_H

#include "GameObject.h"
#include "CartPoint.h"
#include "CartVector.h"
#include "CoralReef.h"
#include "Cave.h"
#include <cmath>

class Cave;

class Fish : public GameObject
{
	public:

		Fish();
		Fish(int, Cave*);

		bool update();
		double get_size();
		void start_swimming(CartPoint);
		void start_eating(CoralReef*);
		bool is_hidden();
		void start_hiding(Cave*);
		void float_in_place();
		void show_status();
		double get_speed();

	private:
		double energy, size, prefeast_size;
		CartPoint destination;
		CartVector delta;
		CoralReef* reef;
		Cave* home;
		bool update_location();
		void setup_destination(CartPoint);
};


#endif 
