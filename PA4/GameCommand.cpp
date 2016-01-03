#include "GameCommand.h"
#include "InputHandling.h"
#include <cstdlib>

using namespace std;

void do_swim_command(Model& model)
{
	int id,x,y;
	if(!(cin >> id >> x >> y))
	{
		throw InvalidInput("Was expecting an integer");
	}

	if(model.fish_ptrs.back()->get_id() < id)
	{
		throw InvalidInput("Invalid Fish ID");
	}

	if(x > 20 || x < 0)
	{
		throw InvalidInput("x coordinate out of bounds");
	}

	if(y > 20 || y < 0)
	{
		throw InvalidInput("y coordinate out of bounds");
	}

	(model.get_Fish_ptr(id))->start_swimming(CartPoint(x,y));

	cout << "Swimming Fish " << id << " to " << "(" << x << "," << y << ")" << endl;
}

void do_go_command(Model& model)
{
	cout << "Advancing one tick" << endl;
	model.update();
	model.show_status();
}

void do_run_command(Model& model)
{
	cout << "Advancing to next event" << endl;

	for(int x = 0; x < 5; x++)
	{
		if(model.update())
		{
			break;
		}
	}

	model.show_status();
}

void do_eat_command(Model& model)
{
	int fid,rid;

	if(!(cin >> fid >> rid))
	{
		throw InvalidInput("Was expecting an integer");
	}

	if(model.fish_ptrs.back()->get_id() < fid)
	{
		throw InvalidInput("Invalid Fish ID");
	}

	if(model.reef_ptrs.back()->get_id() < rid)
	{
		throw InvalidInput("Invalid CoralReef ID");
	}

	(model.get_Fish_ptr(fid))->start_eating(model.get_CoralReef_ptr(rid));
} 

void do_float_command(Model& model)
{
	int fid;
	if(!(cin >> fid))
	{
		throw InvalidInput("Was expecting an integer");
	}

	if(model.fish_ptrs.back()->get_id() < fid)
	{
		throw InvalidInput("Invalid Fish ID");
	}

	model.get_Fish_ptr(fid)->float_in_place();

	cout << "Stopping " << fid << endl;
}

void do_zoom_command(Model& model)
{
	int fid,cid;
	if(!(cin >> fid >> cid))
	{
		throw InvalidInput("Was expecting an integer");
	}

	if(model.fish_ptrs.back()->get_id() < fid)
	{
		throw InvalidInput("Invalid Fish ID");
	}

	if(model.fish_ptrs.back()->get_id() < cid)
	{
		throw InvalidInput("Invalid Fish ID");
	}

	model.get_Fish_ptr(fid)->start_hiding(model.get_Cave_ptr(cid));

	cout << "Zooming fish " << fid << endl;
}

void do_attack_command(Model& model)
{
	int IDOne, IDtwo;
	if(!(cin >> IDOne >> IDtwo))
	{
		throw InvalidInput("Was expecting an integer");
	}

	if(model.fish_ptrs.back()->get_id() < IDOne)
	{
		throw InvalidInput("Invalid Fish ID");
	}

	if(model.fish_ptrs.back()->get_id() < IDtwo)
	{
		throw InvalidInput("Invalid Fish ID");
	}

	model.get_Fish_ptr(IDOne)->start_attack(model.get_Fish_ptr(IDtwo));
}

void handle_new_command(Model& model)
{
	char type;
	int ID,x,y,ID_HOME;
	bool exists = false;
	bool isFull = false;
	Cave *spawn;

	if(!(cin >> type))
		throw InvalidInput("Was expecting a char");

	//First if clause for checking if type is Shark
	if(type == 'S' || type == 's')
	{
		if(!(cin >> ID))
		{
			throw InvalidInput("Was expecting an integer");

			for (list<Fish *>::iterator it = model.fish_ptrs.begin(); it != model.fish_ptrs.end(); it++)
			{
				if((*it)->get_id() == ID)
				{
					exists = true;
				}
			}
		}
	
		if(exists)
		{
			throw InvalidInput("ID already exists for Sharks");
		}
		else
		{
			srand(model.getTime());
			model.addPointer(new Shark(ID));
		}
	}
	//Second if clause for checking if type is Tuna
	else if(type == 'T' || type == 't')
	{
		if(!(cin >> ID >> ID_HOME))
		{
			throw InvalidInput("Was expecting an integer");
		}

		for (list<Fish *>::iterator it = model.fish_ptrs.begin(); it != model.fish_ptrs.end(); it++)
		{
			if((*it)->get_id() == ID)
			{
				exists = true;
			}
		}
		
		for(list<Cave* >::iterator it = model.cave_ptrs.begin(); it != model.cave_ptrs.end(); it++)
		{
			if((*it)->get_id() == ID_HOME)
			{
				spawn = (*it)->getSelf();
				if((*it)->getSpace() < 20)
				{
					isFull = true;
				}
			}
		}

		if(exists || isFull)
		{
			if(exists)
			{
				throw InvalidInput("ID already exists for Fish");
			}

			if(isFull)
			{
				throw InvalidInput("Cave specified does not have enough space");
			}
		}
		else
		{
			Model* modelptr = &model;
			model.addPointer(new Tuna(ID,spawn,modelptr));
		}
	}
	//Third if clause for checking if type is Cave or Reef
	else
	{
		if(type != 'C' && type != 'R' && type !='c' && type != 'r')
			throw InvalidInput("Invalid type");

		if(!(cin >> ID >> x >> y))
			throw InvalidInput("Was expecting an integer");

		if(x > 20 || x < 0)
		{
			throw InvalidInput("X coordinate out of bounds");
		}

		if(y > 20 || y < 0)
		{
			throw InvalidInput("Y coordinate out of bounds");
		}

		for(list<GameObject* >::iterator it = model.object_ptrs.begin(); it != model.object_ptrs.end(); it++)
		{
			if((*it)->get_id() == ID && (*it)->get_display_code() == type)
			{
				exists = true;
			}
		}
		
		if(exists)
		{
			if(type == 'C' || type == 'c')
			{
				throw InvalidInput("ID already exists for Caves");
			}
			else
			{
				throw InvalidInput("ID already exists for Coral Reefs");
			}
		}
		else
		{
			if(type == 'C' || type == 'c')
			{
				model.addPointer(new Cave(ID,CartPoint(x,y)));
			}
			else
			{
				model.addPointer(new CoralReef(ID,CartPoint(x,y)));
			}
		}
	}
}
