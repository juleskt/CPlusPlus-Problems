#include "GameCommand.h"

using namespace std;


void do_swim_command(Model& model)
{
	int id,x,y;

	cin >> id >> x >> y;

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

	cin >> fid >> rid;

	(model.get_Fish_ptr(fid))->start_eating(model.get_CoralReef_ptr(rid));
} 

void do_float_command(Model& model)
{
	int fid;

	cin >> fid;

	model.get_Fish_ptr(fid)->float_in_place();

	cout << "Stopping " << fid << endl;
}

void do_zoom_command(Model& model)
{
	int fid,cid;

	cin >> fid >> cid;

	model.get_Fish_ptr(fid)->start_hiding(model.get_Cave_ptr(cid));

	cout << "Zooming fish " << fid << endl;
}
