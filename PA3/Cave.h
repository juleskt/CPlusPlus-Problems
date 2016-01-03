#ifndef CAVE_H
#define CAVE_H

#include "GameObject.h"
#include "CartPoint.h"
#include "Fish.h"

class Fish;

class Cave : public GameObject
{
	public:

		Cave();
		Cave(int, CartPoint);

		bool hide_fish(Fish* fish_to_hide);
		bool release_fish(Fish* fish_to_release);
		bool update();
		void show_status();

	private:
		double space;
};

#endif