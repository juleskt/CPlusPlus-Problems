#ifndef CORALREEF_H
#define CORALREEF_H

#include "CartPoint.h"
#include "GameObject.h"

class CoralReef : public GameObject
{
	public:

		//Default Constructor @@@@@@@@@@@@@@@@@@@@ FIX DEFAULT
		CoralReef(); 
		
		//Constructor
		CoralReef(int in_d, CartPoint in_loc);

		bool is_empty();
		double provide_food(double amount_to_provide = 20);
		bool update();
		void show_status();
		
	private:
		double amount;
};
#endif