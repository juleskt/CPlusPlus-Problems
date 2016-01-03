#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "CartPoint.h"

using namespace std;

class GameObject
{
	public:
		
		GameObject(char, int);
		GameObject(char, int, CartPoint);
		virtual ~GameObject();

		CartPoint get_location();
		virtual int get_id();
		
		virtual void drawself(char* grid);
		virtual void show_status();
		virtual bool update();
		virtual bool is_alive();
		virtual char get_display_code();

	private:
		int id_num;

	protected:
		CartPoint location;
		char display_code;
		char state;
};

#endif