#include "CoralReef.h"
#include <iostream>

using namespace std;

CoralReef::CoralReef() : GameObject('R', 0) // CoralReef::CoralReef() : GameObject('R',0) CoralReef Reef;
{
	//FIX THE DEFAULT CONSTRUCTOR FOR CORAL @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
	display_code = 'R';
	state = 'f';
	amount = 100;

	cout << "CoralReef default constructed." << endl;
}

CoralReef::CoralReef(int in_id, CartPoint in_loc) : GameObject('R',in_id,in_loc)
{
	state = 'f';
	amount = 100;
	cout << "CoralReef constructed" << endl;
}

bool CoralReef::is_empty()
{
	if (this->amount == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

double CoralReef::provide_food(double amount_to_provide)
{
	double left;

	if (this->amount >= amount_to_provide)
	{
		this->amount = this->amount - amount_to_provide;
		return amount_to_provide;
	}
	else
	{
		left = this->amount;
		this->amount = 0;
		return left;
	}
}

bool CoralReef::update()
{
	 int already_empty = 0;
	if (this->is_empty() && already_empty == 0)
	{
		this->state = 'e';
		this->display_code = 'r';

		cout << "CoralReef " << "<" << get_id() << "> " << "has been depleted" << endl;
		already_empty++;
		return true;
	}
	else
	{
		return false;
	}

}

void CoralReef::show_status()
{
	cout << "CoralReef status: " << display_code <<" with ID " << get_id() <<" at location " 
	<<  location << " containing food " << amount << endl;
}

/*void CoralReef::save(ofstream& file)
{
	GameObject::save(file);
	file << amount << endl;
}

void CoralReef::restore(ifstream& file, Model& model)
{
	GameObject::restore(file);
	file >> amount;
}*/