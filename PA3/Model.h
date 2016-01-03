#ifndef MODEL_H
#define MODEL_H

#include "GameObject.h"
#include "Fish.h"
#include "Cave.h"
#include "CoralReef.h"
#include "View.h"

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

	private:
		int time;
		int num_objects;
		int num_fish;
		int num_caves;
		int num_reefs;
		
		GameObject* object_ptrs [10];
		Fish* fish_ptrs [10];
		Cave* cave_ptrs [10];
		CoralReef* reef_ptrs [10];
};

#endif