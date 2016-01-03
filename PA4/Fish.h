#ifndef FISH_H
#define FISH_H

#include "GameObject.h"
#include "CoralReef.h"
#include "Cave.h"
#include <cmath>
//#include "Model.h"

class Cave;
class Model;

class Fish : public GameObject
{
	public:

		Fish(char,int);
		Fish(char,int,Cave*,int);
		Fish(char,int,CartPoint,int);

		virtual void start_attack(Fish*);
		virtual void start_mating(Fish*);
		void get_bitten(int attack_strength);
		virtual double get_speed() = 0;
		virtual bool update();
		double get_size();
		void start_swimming(CartPoint);
		void start_eating(CoralReef*);
		bool is_hidden();
		void start_hiding(Cave*);
		void float_in_place();
		void show_status();

		void set_prefeast_size(double);
		void set_size(double);
		double get_prefeast_size();
		double get_energy();
		Cave* get_home();
		bool is_alive();
		CoralReef* get_reef();
		void set_dest(CartPoint);

	private:
		double energy, size, prefeast_size;
		CartPoint destination;
		CartVector delta;
		CoralReef* reef;
		Cave* home;
		bool update_location();
		void setup_destination(CartPoint);

	protected:
		Model* world;
};

#endif 
