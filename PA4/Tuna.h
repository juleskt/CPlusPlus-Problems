#ifndef TUNA_H
#define TUNA_H

#include "Fish.h"
#include "GameObject.h"
#include "Cave.h"
#include "Model.h"

class Model;

class Tuna : public Fish
{
	public:
		Tuna();
		Tuna(int,Cave*,Model*);
		double get_speed();
		void start_mating(Tuna* fish_mate);
		bool update();
		void show_status();
		int ticks;
		bool initiator;
		void do_mating();
};

#endif