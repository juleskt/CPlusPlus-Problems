#ifndef MODEL_H
#define MODEL_H

#include "GameObject.h"
#include "Fish.h"
#include "Cave.h"
#include "CoralReef.h"
#include "View.h"
#include "Tuna.h"
#include "Shark.h"
#include <list>

class Fish;
class Tuna;

class Model
{
	public:
		
		Model();
		~Model();

		Fish* get_Fish_ptr(int id_num);
		CoralReef* get_CoralReef_ptr(int id_num);
		Cave* get_Cave_ptr(int id_num);

		bool update();
		void display(View& view);
		void show_status();
		Tuna* find_mate(Tuna*);
		void makeTuna(Cave*);

		list <GameObject*> getObjPtrs();
		list <GameObject*> getActPtrs();
		list <Fish*> getFishPtrs();

		list <GameObject*> object_ptrs;
		list <GameObject*> active_ptrs;
		list <Fish*> fish_ptrs;
		list <Cave*> cave_ptrs;
		list <CoralReef*> reef_ptrs;

		void addPointer(GameObject*);

		int getTime();

		void deletePtr(Fish*);
	
	private:
		int time;
		int num_objects;
		int num_fish;
		int num_caves;
		int num_reefs;
};

#endif