#include "Model.h"

Model::Model()
{
	time = 0;

	Cave* c1ptr = new Cave(1,CartPoint(5,1));
	Cave* c2ptr = new Cave(2,CartPoint(6,2));

	Fish* f1ptr = new Fish(1,c1ptr);
	Fish* f2ptr = new Fish(2,c2ptr);

	CoralReef* cfptr1 = new CoralReef(1,CartPoint(1,20));
	CoralReef* cfptr2 = new CoralReef(2,CartPoint(20,1));
	CoralReef* cfptr3 = new CoralReef(3,CartPoint(20,20));

	object_ptrs [0] = cave_ptrs[0] = c1ptr;
	object_ptrs [1] = cave_ptrs[1] = c2ptr;
	object_ptrs [2] = fish_ptrs[0] = f1ptr;
	object_ptrs [3] = fish_ptrs[1] = f2ptr;
	object_ptrs [4] = reef_ptrs[0] = cfptr1;
	object_ptrs [5] = reef_ptrs[1] = cfptr2;
	object_ptrs [6] = reef_ptrs[2] = cfptr3;
	
	num_objects = 7;
	num_fish = 2;
	num_reefs = 3;
	num_caves = 2;

	cout << "Model default constructed" << endl;
}

Model::~Model()
{
	for(int x = 0; x < num_objects; x++)
	{
		delete object_ptrs[x];
	}

	cout << "Model destructed" << endl;
}

Fish* Model::get_Fish_ptr(int id_num)
{
	for (int x = 0; x < num_fish; x++)
	{
		if(fish_ptrs[x]->get_id() == id_num)
		{
			return fish_ptrs[x];
		}
	}
}

CoralReef* Model::get_CoralReef_ptr(int id_num)
{
	for(int x = 0; x < num_reefs; x++)
	{
		if(reef_ptrs[x]->get_id() == id_num)
		{
			return reef_ptrs[x];
		}
	}
}

Cave* Model::get_Cave_ptr(int id_num)
{
	for(int x = 0; x < num_caves; x++)
	{
		if(cave_ptrs[x]->get_id() == id_num)
		{
			return cave_ptrs[x];
		}
	}
}

bool Model::update()
{
	bool flag = false;
	time++;
	for(int x = 0; x < num_objects; x++)
	{
		if(object_ptrs[x]->update())
		{
			flag = true;
		}
	}
	return flag;
}

void Model::display(View& view)
{
	cout << "Time: " << time << endl;
	
	view.clear();
	
	for(int x = 0; x < num_objects; x++)
	{
		view.plot(object_ptrs[x]);
	}

	view.draw();
}

void Model::show_status()
{
	for(int x = 0; x < num_objects; x++)
	{
		object_ptrs[x]->show_status();
	}
}