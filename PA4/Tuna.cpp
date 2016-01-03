#include "Tuna.h"

Tuna::Tuna() : Fish('T',10)
{
	set_prefeast_size(10);
	ticks = 0;
	initiator = false;
}

Tuna::Tuna(int id,Cave* home, Model* world) : Fish('T',id,home,10)
{
	set_prefeast_size(10);
	ticks = 0;
	initiator = false;
	this->world = world;
}

double Tuna::get_speed()
{
	return (1/get_size())*get_energy()*4;
}

void Tuna::start_mating(Tuna* fish_mate)
{
	if(this->get_home() == fish_mate->get_home() && this->get_home()->getSpace() > 20) 
	{
		if(this->get_size() <= 60 && this->get_size() >= 40 && fish_mate->get_size() <= 60 )
		{
			if(fish_mate->get_size() >= 40 && this->get_home()->numFish == 2)
			{
				initiator = true;
				do_mating();
				fish_mate->do_mating();
			}
		}
	}
}

bool Tuna::update()
{
	switch(state)
	{
		case 'm':

			if(ticks == 2 && initiator == true)
			{
				world->makeTuna(this->get_home());
			}
			else
			{
				ticks++;
				return false;
			}
		break;

		case 'h':
			start_mating(world->find_mate(this));

		break;
	}
	this->Fish::update();
}

void Tuna::show_status()
{
	cout << "Tuna status: ";
	this->Fish::show_status();
}

void Tuna::do_mating()
{
	cout << "I found a mate!" << endl;
	state = 'm';
}

/*void Tuna::save(ofstream& file)
{
	Fish::save(file);
	file << ticks << endl << ticks << initiator << endl;
}

void Tuna::restore(ifstream& file, Model& model)
{
	Fish::restore(file);
	file >> ticks >> endl >> ticks >> initiator >> endl;
}*/