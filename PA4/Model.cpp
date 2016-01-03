#include "Model.h"
#include <cstdlib>

Model::Model()
{
	time = 0;

	Cave* c1ptr = new Cave(1,CartPoint(5,1));
	Cave* c2ptr = new Cave(2,CartPoint(6,2));

	object_ptrs.push_back(c1ptr);
	active_ptrs.push_back(c1ptr);
	cave_ptrs.push_back(c1ptr);

	object_ptrs.push_back(c2ptr);
	active_ptrs.push_back(c2ptr);
	cave_ptrs.push_back(c2ptr);

	Tuna* t1ptr = new Tuna(1,c1ptr,this);
	Tuna* t2ptr = new Tuna(2,c2ptr,this);
	Tuna* t3ptr = new Tuna(3,c2ptr,this);

	object_ptrs.push_back(t1ptr);
	active_ptrs.push_back(t1ptr);
	fish_ptrs.push_back(t1ptr);

	object_ptrs.push_back(t2ptr);
	active_ptrs.push_back(t2ptr);
	fish_ptrs.push_back(t2ptr);

	object_ptrs.push_back(t3ptr);
	active_ptrs.push_back(t3ptr);
	fish_ptrs.push_back(t3ptr);

	srand(time);
	Shark* sptr1 = new Shark(4);
	srand(time);
	Shark* sptr2 = new Shark(5);

	object_ptrs.push_back(sptr1);
	active_ptrs.push_back(sptr1);
	fish_ptrs.push_back(sptr1);

	object_ptrs.push_back(sptr2);
	active_ptrs.push_back(sptr2);
	fish_ptrs.push_back(sptr2);

	CoralReef* cfptr1 = new CoralReef(1,CartPoint(1,20));
	CoralReef* cfptr2 = new CoralReef(2,CartPoint(20,1));
	CoralReef* cfptr3 = new CoralReef(3,CartPoint(20,20));

	object_ptrs.push_back(cfptr1);
	active_ptrs.push_back(cfptr1);
	reef_ptrs.push_back(cfptr1);

	object_ptrs.push_back(cfptr2);
	active_ptrs.push_back(cfptr2);
	reef_ptrs.push_back(cfptr2);

	object_ptrs.push_back(cfptr3);
	active_ptrs.push_back(cfptr3);
	reef_ptrs.push_back(cfptr3);

	cout << "Model default constructed" << endl;
}

//Deletes all objects when Model is deconstructed
Model::~Model()
{	
	for (list<GameObject *>::iterator it = object_ptrs.begin(); it != object_ptrs.end(); it++)
	{
		delete *it;
	}

	cout << "Model destructed" << endl;
}

//Looks for a fish with a certain ID and returns
Fish* Model::get_Fish_ptr(int id_num)
{
	for (list<Fish *>::iterator it = fish_ptrs.begin(); it != fish_ptrs.end(); it++)
	{
		if((*it)->get_id() == id_num)
		{
			return *it;
		}
	}
}

//Looks for a reef with a certain ID and returns
CoralReef* Model::get_CoralReef_ptr(int id_num)
{
	for(list<CoralReef *>::iterator it = reef_ptrs.begin(); it != reef_ptrs.end(); it++)
	{
		if((*it)->get_id() == id_num)
		{
			return *it;
		}
	}
}

//Looks for a cave with a certain ID and returns
Cave* Model::get_Cave_ptr(int id_num)
{
	for(list<Cave *>::iterator it = cave_ptrs.begin(); it != cave_ptrs.end(); it++)
	{
		if((*it)->get_id() == id_num)
		{
			return *it;
		}
	}
}

bool Model::update()
{
	bool flag = false;
	time++;
	
	for(list<GameObject *>::iterator it = active_ptrs.begin(); it != active_ptrs.end(); it++)
	{
		if((*it)->update())
		{
			flag = true;
		}
	}
	
	/*for(list<GameObject *>::iterator it = active_ptrs.end(); it != active_ptrs.begin(); it++)
	{
		if(dynamic_cast<Tuna*>(*it))
		{
			if(!(*it)->is_alive())
			{
				active_ptrs.remove(*it);
				cout << "Dead object removed" << endl;
			}
			else
			{
				cout << "Plserino" << endl;
				continue;
			}
		}
	}*/

	if(flag)
	{
		return true;
	}
}

void Model::display(View& view)
{
	cout << "Time: " << time << endl;
	
	view.clear();
	
	for(list<GameObject *>::iterator it = active_ptrs.begin(); it != active_ptrs.end(); it++)
	{
		view.plot(*it);
	}

	view.draw();
}

void Model::show_status()
{
	cout << "---Fish---" << endl;
	for(list<Fish *>::iterator it = fish_ptrs.begin(); it != fish_ptrs.end(); it++)
	{
		(*it)->show_status();
	}

	cout << "---Cave---" << endl;
	for(list<Cave *>::iterator it = cave_ptrs.begin(); it != cave_ptrs.end(); it++)
	{
		(*it)->show_status();
	}

	cout << "---Reef---" << endl;
	for(list<CoralReef *>::iterator it = reef_ptrs.begin(); it != reef_ptrs.end(); it++)
	{
		(*it)->show_status();
	}


	/*for(list<GameObject *>::iterator it = object_ptrs.begin(); it != object_ptrs.end(); it++)
	{
		(*it)->show_status();
	}*/
}

Tuna* Model::find_mate(Tuna* looking)
{
	for(list<Fish *>::iterator it = fish_ptrs.begin(); it != fish_ptrs.end(); it++)
	{
		if(looking->get_home() == (*it)->get_home())
		{
			if(looking->get_id() != (*it)->get_id())
			{
				return dynamic_cast<Tuna*>(*it);
			}
		}
	}
}

list <GameObject*> Model::getObjPtrs()
{
	return object_ptrs;
}

list <GameObject*> Model::getActPtrs()
{
	return active_ptrs;
}

list <Fish*> Model::getFishPtrs()
{
	return fish_ptrs;
}

void Model::makeTuna(Cave* cavePtr)
{
	int id;
	//NEED TO IMPLEMENT THE NEW ID FUNCTION, NOT LAST ON LIST

	object_ptrs.push_back(new Tuna(fish_ptrs.back()->get_id()+1,cavePtr,this));
	active_ptrs.push_back(new Tuna(fish_ptrs.back()->get_id()+1,cavePtr,this));
	fish_ptrs.push_back(new Tuna(fish_ptrs.back()->get_id()+1,cavePtr,this));
}

void Model::addPointer(GameObject* newPtr)
{
	if(dynamic_cast<Shark*>(newPtr) != NULL)
	{
		object_ptrs.push_back(dynamic_cast<Shark*>(newPtr));
		active_ptrs.push_back(dynamic_cast<Shark*>(newPtr));
		fish_ptrs.push_back(dynamic_cast<Shark*>(newPtr));
	}
	else if (dynamic_cast<Tuna*>(newPtr) != NULL)
	{
		object_ptrs.push_back(dynamic_cast<Tuna*>(newPtr));
		active_ptrs.push_back(dynamic_cast<Tuna*>(newPtr));
		fish_ptrs.push_back(dynamic_cast<Tuna*>(newPtr));
	}
	else if (dynamic_cast<Cave*>(newPtr) != NULL)
	{
		object_ptrs.push_back(dynamic_cast<Cave*>(newPtr));
		active_ptrs.push_back(dynamic_cast<Cave*>(newPtr));
		cave_ptrs.push_back(dynamic_cast<Cave*>(newPtr));
	}
	else if (dynamic_cast<CoralReef*>(newPtr) != NULL)
	{
		object_ptrs.push_back(dynamic_cast<CoralReef*>(newPtr));
		active_ptrs.push_back(dynamic_cast<CoralReef*>(newPtr));
		reef_ptrs.push_back(dynamic_cast<CoralReef*>(newPtr));
	}
}

int Model::getTime()
{
	return time;
}

void Model::deletePtr(Fish* ptr)
{
	delete ptr;
}

/*void Model::save(ofstream& file)
{
	file << time << endl << active_ptrs.size() << endl; //First line is always time

	for(list<GameObject *>::iterator it = active_ptrs.begin(); it != active_ptrs.end(); it++)
	{
		file << (*it)->get_display_code(); << (*it)->get_id() << endl;
	}

	for(list<GameObject *>::iterator it = active_ptrs.begin(); it != active_ptrs.end(); it++)
	{
		(*it)->save(file);
	}
}*/
		
/*void Model::restore(ifstream& file)
{
	object_ptrs.clear();
	active_ptrs.clear();
	fish_ptrs.clear();
	cave_ptrs.clear();
	reef_ptrs.clear();

	int currLine = 1; //keeps track of current line
	int numObj = 10; //Max it can have, just in case

	if(currLine == 1)
	{
		file >> time;
	}

	else if(currLine == 2)
	{
		file >> numObj;
	}

	else
	{
		for(int x = 0; x < numObj; x++)
		{
			string in;
			
			file >> in;

			switch (in[0])
			{
				case 'T':

				Tuna* tunaPtr = new Tuna();
				tunaPtr->set_display_code('T');
				tunaPtr->set_id_num(in[1]);

				object_ptrs.push_back(tunaPtr);
      	    	active_ptrs.push_back(tunaPtr);
      	    	fish_ptrs.push_back(tunaPtr);
				break;

				case 'S':

				Shark* tunaPtr = new Shark();
				tunaPtr->set_display_code('S');
				tunaPtr->set_id_num(in[1]);

				object_ptrs.push_back(tunaPtr);
      	    	active_ptrs.push_back(tunaPtr);
      	    	fish_ptrs.push_back(tunaPtr);
				break;

				case 'R':

				CoralReef* tunaPtr = new CoralReef();
				tunaPtr->set_display_code('R');
				tunaPtr->set_id_num(in[1]);

				object_ptrs.push_back(tunaPtr);
      	    	active_ptrs.push_back(tunaPtr);
      	    	reef_ptrs.push_back(tunaPtr);
				break;

				case 'r':

				CoralReef* tunaPtr = new CoralReef();
				tunaPtr->set_display_code('r');
				tunaPtr->set_id_num(in[1]);

				object_ptrs.push_back(tunaPtr);
      	    	active_ptrs.push_back(tunaPtr);
      	    	reef_ptrs.push_back(tunaPtr);
				break;

				case 'C':

				Cave* tunaPtr = new Cave();
				tunaPtr->set_display_code('C');
				tunaPtr->set_id_num(in[1]);

				object_ptrs.push_back(tunaPtr);
      	    	active_ptrs.push_back(tunaPtr);
      	    	cave_ptrs.push_back(tunaPtr);
				break;

				case 'c':

				Cave* tunaPtr = new Cave();
				tunaPtr->set_display_code('c');
				tunaPtr->set_id_num(in[1]);

				object_ptrs.push_back(tunaPtr);
      	    	active_ptrs.push_back(tunaPtr);
      	    	cave_ptrs.push_back(tunaPtr);
				break;
			}
		}
	}

	for(list<GameObject *>::iterator it = object_ptrs.begin(); it != object_ptrs.end(); it++)
	{
		(*it)->restore(file,this);
	}
}*/