#include "Shark.h"
#include <cstdlib>

Shark::Shark() : Fish('S',20)
{
	set_prefeast_size(20);
	attack_strength = 2;
}

//Random location for x and y BASED ON SEED @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
Shark::Shark(int in_id) : Fish('S',in_id,CartPoint(rand()%20,rand()%20),20) // @@@@@@@@@@@@@@@@@@@@@@@@@
{
	set_prefeast_size(20);
	attack_strength = 2;
}

Shark::~Shark()
{

}

double Shark::get_speed()
{
	return (1/get_size())*get_energy()*8;
}

void Shark::start_attack(Fish* target)
{
	if(cart_distance(this->get_location(),target->get_location()) <= 1)
	{
		target->get_bitten(attack_strength);
		cout << "Chomp!" << endl;
		this->target = target;
		state = 'a';
	}
	else
	{
		cout << "Fish are friends, not food" << endl;
	}
}

bool Shark::update()
{
	switch(state)
	{
		case 'x':
			return false;
		break;

		case 's':
			return false;
		break;

		case 'e':
		{
			if(get_size() < 2*get_prefeast_size())
			{
				double amount_eaten = get_reef()->provide_food();
				if(amount_eaten > 0)
				{
					set_size(get_size() + amount_eaten/2);
					cout << display_code << get_id() << ": Grew to size " << get_size() << endl; 
					return false;
				}
				else
				{
					state = 'f';
					cout << display_code << get_id() << ": This reef has no more food for me" << endl;
					set_prefeast_size(get_size());
					return false;
				}
			}
			else
			{
				set_prefeast_size(get_size());
				cout << display_code << get_id() << ": I'm full. I'm heading home" << endl;
				set_dest(get_home()->get_location());
				state = 'z';
				return true;
			}
		}
		break;

		case 'a':
			if(cart_distance(this->get_location(),target->get_location()) > 1)
			{
				cout << "Darn! It escaped." << endl;
				target = NULL;
				state = 's';
				return true;
			}
			else
			{
				if(target->is_alive())
				{
					target->get_bitten(attack_strength);
					cout << "Chomp!" << endl;
					return false;
				}
				else
				{
					cout << "I triumph!" << endl;
					state = 's';
					return true;
				}
			}
		break;
	}
}

void Shark::show_status()
{
	cout << "Shark status: ";
	this->Fish::show_status();
}

void Shark::start_mating()
{
  cout << "My primary goal is to hunt tunas" << endl;
}
