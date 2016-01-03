#include "Fish.h"

using namespace std;

//Default Constructor
Fish::Fish() : GameObject('F',0)
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
Fish::Fish(int in_id, Cave* home) : GameObject('F',in_id,home->get_location())
{
	//Initializations
	size = 10;
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
				return false;
		break;
		
		case 's':
				if(update_location())
				{
					state = 'f';
					return true;
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
					 cout << display_code << get_id() << ": Is hidden in Cave " << home->get_id() << endl;
					return false;
				}
		break;
		
		case 'p': 
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
	cout << "Fish status: " << display_code << " with ID " << get_id() << " at location " 
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
		
		case 'e':  cout <<"Is eating at Reef " << reef->get_id() << endl;
		break;
		
		case 'z': cout <<"Is swimming to Cave " << home->get_id() << " With a speed of " << get_speed() << endl;
		break;
		
		case 'h': cout << "Is hidden in Cave " << home->get_id() << endl;
		break;
		
		case 'p': cout << "Is panicked" << endl;
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
