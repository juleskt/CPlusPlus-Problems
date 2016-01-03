#include "Cave.h"

using namespace std;

Cave::Cave() : GameObject('C',0)
{
	state = 'e';
	space = 1000;
	cout << "Cave default constructed" << endl;
}

Cave::Cave(int in_id, CartPoint in_loc) : GameObject('c',in_id,in_loc)
{
	state = 'e';
	space = 100;
	cout << "Cave constructed" << endl;
}

bool Cave::hide_fish(Fish* fish_to_hide)
{
	if(fish_to_hide->is_hidden() == false)
	{
		if (fish_to_hide->get_size() > space)
		{
			return false;
		}
		else
		{
			space -= fish_to_hide->get_size();
			return true;
			numFish++;
		}
	}
	else
	{
		return false;
	}
}

bool Cave::release_fish(Fish* fish_to_release)
{
	if(fish_to_release->is_hidden())
	{
		space += fish_to_release->get_size();
		return true;
		numFish--;
	}
	else
	{
		return false;
	}
}

bool Cave::update()
{
	if(space == 0)
	{
		state = 'p';
		cout << "Cave " << get_id() << " is packed like sardines" << endl;
		return true;
	}
	else
	{
		return false;
	}
}

void Cave::show_status()
{
	cout << "Cave status: " << display_code << " with ID " << get_id() <<" at location " 
	<< location << " has a space of " << space << endl;
}

double Cave::getSpace()
{
	return this->space;
}

Cave * Cave::getSelf()
{
	return this;
}

/*void Cave::save(ofstream& file)
{
	GameObject::save(file);
	file << space << endl << numFish << endl;
}

void Cave::restore(ifstream& file, Model& model)
{
	GameObject::restore(file);
	file >> space >> endl >> numFish >> endl;
}*/