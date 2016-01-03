#ifndef SHARK_H
#define SHARK_H

#include "Fish.h"

class Shark : public Fish
{
	public:
		Shark();
		Shark(int);
		~Shark();
		double get_speed();
		void start_attack(Fish* target);
		bool update();
		void show_status();
		int get_attack_strength();
		void start_mating();

	private:
		int attack_strength;
		double range;
		Fish* target;
};

#endif
