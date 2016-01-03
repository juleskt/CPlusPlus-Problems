#include "Fish.h"
#include "Model.h"
#include <iostream>

using namespace std;

//Default Constructor
Fish::Fish(char,int) : GameObject('F',0)
{
	//Initializations
	state = 'h';
	size = 10;
	prefeast_size = size;
	energy = 15;
	reef = NULL;
	home = NULL;
	cout << "Fish default constructed" << endl;
}

//Constructor
Fish::Fish(char display_code, int in_id, Cave* home, int size) : GameObject(display_code,in_id,home->get_location())
{
	//Initializations
	this->size = size;
	prefeast_size = size;
	energy = 15;
	reef = NULL;
	this->home = home;

	//Calls Cave::hide_fish to hide this instance of fish
	if(home->hide_fish(this))
	{
		cout << "Fish constructed" << endl;
	}

	state = 'h';
} 

Fish::Fish(char display_code, int in_id, CartPoint loc ,int size) : GameObject(display_code,in_id,loc)
{
	this->home = NULL;
	this->size = size;
	prefeast_size = size;
	energy = 15;
	state = 'f';
}

void Fish::start_attack(Fish*)
{
	cout << "I cannot attack." << endl;
}

void Fish::start_mating(Fish*)
{
	cout << "I cannot mate." << endl;
}

void Fish::get_bitten(int attack_strength)
{
	this->energy = energy-attack_strength;

	if(this->energy <= 0)
	{
		cout << "Oh no, I've become chum!" << endl;
		state = 'x';
	}
	else
	{
		cout << "Ouch!" << endl;
	}
}

void Fish::setup_destination(CartPoint dest)
{
	destination = dest;
	delta = (dest - get_location()) * (get_speed()/cart_distance(dest,get_location()));
}

bool Fish::update()
{
	switch(state)
	{
		case 'f':
			if(is_alive())
			{
				return false;
			}
			else
			{
				return false;
			}
		break;
		
		case 's':
			if(is_alive())
			{
				if(update_location())
				{
					state = 'f';
					return true;
				}
				else
				{
					return false;
				}
			}
			else
			{
				return false;
			}
		break;
		
		case 'o':
				if(update_location())
				{
					state = 'e';
					cout << display_code << get_id() << ": Starting to dine at a coral reef" << endl;
					return true;
				}
				else
				{
					return false;
				}
		break;
		
		case 'e':
		{
				if(size < 2*prefeast_size)
				{
					double amount_eaten = reef->provide_food();
					if(amount_eaten > 0)
					{
						size+=(amount_eaten/2);
						cout << display_code << get_id() << ": Grew to size " << size << endl; 
						return false;
					}
					else
					{
						state = 'f';
						cout << display_code << get_id() << ": This reef has no more food for me" << endl;
						prefeast_size = size;
						return false;
					}
				}
				else
				{
					prefeast_size = size;
					cout << display_code << get_id() << ": I'm full. I'm heading home" << endl;
					setup_destination(home->get_location());
					state = 'z';
					return true;
				}
		}
		break;
		
		case 'z':
				if(update_location())
				{
					if(home->hide_fish(this))
					{
						state = 'h';
						cout << display_code << get_id() << ": I am hidden and safe" << endl;
						return true;
					}
					else
					{
						state = 'p';
						cout << display_code << get_id() << ": Help! My home is full" << endl;
						return false;
					}
				}
		break;
		
		case 'h':
				if(is_hidden())
				{
					energy = energy*(.75);

					if(energy > 5)
					{
						cout << display_code << get_id() << ": Is hidden in Cave " << home->get_id() << endl;
						return false;
					}
					else
					{
						state = 'x';
					}
				}
		break;
		
		case 'p': 
				return false;
		break;
		
		case 'x':
			return false;
		break;

	}
}

double Fish::get_size()
{
	return size;
}

void Fish::start_swimming(CartPoint dest) //not done
{	
	if(!is_alive())
	{
		cout << display_code << get_id() << " is dead!" << endl;
	}

	if(is_hidden())
	{
		home->release_fish(this);
	}
		setup_destination(dest);
		state = 's';
		//cout << "Swimming " << get_id() << " to destination " << destination << endl;
		cout << display_code << get_id() << ": on my way" << endl;
}

void Fish::start_eating(CoralReef* destReef)
{

	if(!is_alive())
	{
		cout << display_code << get_id() << " is dead!" << endl;
	}

	if(is_hidden())
	{
		home->release_fish(this);
	}
	
	reef = destReef;
	state = 'o';
	setup_destination(destReef->get_location());
	cout << "Fish "<< get_id() << " eating at CoralReef " << destReef->get_id() << " and returning back to Cave " << home->get_id() << endl;
	cout << display_code << get_id() << ": Food here I come!" << endl;
	if(size == prefeast_size*2)
	{
		//state = 'o';
		//setup_destination(home->get_location());
		cout << "Fish " << get_id() << " eating at CoralReef " << destReef->get_id() <<
		" and returning back to Cave " << home->get_id() << endl;
	}
}

bool Fish::is_hidden()
{
	if(state == 'h')
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Fish::start_hiding(Cave* destCave)
{
	home = destCave;
	setup_destination(destCave->get_location());
	
	state = 'z';
	
	cout << "Fish " << get_id() << ": swimming to cave " << destCave->get_id() << endl;
	cout << display_code << get_id() << ": Off to safety" << endl;

}

void Fish::float_in_place()
{
	state = 'f';

	cout << "Stopping " << get_id() << "." << endl;
	cout << display_code << get_id() << ": Resting my fins." << endl;
}

void Fish::show_status()
{
	cout << display_code << " with ID " << get_id() << " at location " 
	<< get_location() << " ";

	//Series of case statements that vary based on the fish's state
	switch(state)
	{
		case 'f': cout <<"Is floating. Has size of: " << size << " And energy of: " << energy << endl;
		break;
		
		case 's': cout <<"Has a speed of: " << get_speed() << " And is heading to " << destination << endl; 	
		break;
		
		case 'o': cout <<"Is outbound to Reef: " << reef->get_id() << " With a speed of " << get_speed() << endl;
		break;
		
		//ASK ABOUT PREFEAST SIZE!!!!!!!!!@@@@@@@@@@@@@@@@@@@@@@@
		case 'e':  cout <<"Is eating at Reef " << reef->get_id() << endl;
		break;
		
		case 'z': cout <<"Is swimming to Cave " << home->get_id() << " With a speed of " << get_speed() << endl;
		break;
		
		case 'h': cout << "Is hidden in Cave " << home->get_id() << endl;
		break;
		
		case 'p': cout << "Is panicked" << endl;
		break;

		case 'x': cout << "Is dead" << endl;
		break;
	}
}

double Fish::get_speed()
{
	return (1/size)*(energy)*5;;
}


bool Fish::update_location()
{
	if(fabs(destination.x-location.x) <= fabs(delta.x) && fabs(destination.y-location.y) <= fabs(delta.y))
	{
		this->location = destination;
		cout << display_code << get_id() <<  ": I'm there!" << endl;
		return true;
	}
	else
	{
		location = location + delta;
		cout << display_code << get_id() <<": just keep swimming..." << endl;
		return false;
	}
}

void Fish::set_prefeast_size(double prefeast)
{
	prefeast_size = prefeast;
}

void Fish::set_size(double size)
{
	this->size = size;
}

Cave* Fish::get_home()
{
	return home;
}

double Fish::get_energy()
{
	return this->energy;
}

bool Fish::is_alive()
{
	if(state != 'x')
	{
		return true;
	}
	else
	{
		return false;
	}
}

double Fish::get_prefeast_size()
{
	return prefeast_size;
}

CoralReef* Fish::get_reef()
{
	return this->reef;
}

void Fish::set_dest(CartPoint dest)
{
	setup_destination(dest);
}

/*void Fish::save(ofstream& file)
{
	GameObject::save(file);
	file << energy << endl << size << endl << prefeast_size << endl << destination << endl
	<< delta << endl << reef<< endl << home << endl;
}

void Fish::restore(ifstream& file, Model& model)
{
	GameObject::restore(file,model)
	file >> energy >> endl >> size >> endl >> prefeast_size >> endl >> destination >> endl
	>> delta >> endl >> reef >> endl >> home >> endl;
}*/