#include "GameObject.h"
#include <iostream>

using namespace std;

GameObject::GameObject(char in_code, int in_id)
{
	id_num = in_id;
	display_code = in_code;
	cout << "GameObject default constructed." << endl;
}

GameObject::GameObject(char in_code, int in_id, CartPoint in_loc)
{
	id_num = in_id;
	display_code = in_code;
	location = in_loc;
	cout << "GameObject constructed." << endl;
}

GameObject::~GameObject()
{
	cout << "GameObject destructed" << endl;
}


CartPoint GameObject::get_location()
{
	return location;
}

int GameObject::get_id()
{
	return id_num;
}

void GameObject::drawself(char* grid)
{
	*grid = display_code;
	*(grid+1) = '0' + id_num;
}

void GameObject::show_status()
{
	cout << "<" << display_code << ">" << " with ID " << "<" << id_num << ">" <<" at location " 
	<< "<" << location << ">" << endl;
}

bool GameObject::update()
{
	return true;
}

bool GameObject::is_alive()
{
	return true;
}

char GameObject::get_display_code()
{
	return display_code;
}
