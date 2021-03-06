#include "CartPoint.h"
#include "CartVector.h"
#include "GameObject.h"
#include "CoralReef.h"
#include "Cave.h"
#include "Fish.h"
#include "Model.h"
#include "View.h"
#include "GameCommand.h"
#include "InputHandling.h"
#include "Sharknado.h"
#include <iostream>

using namespace std;

int main()
{
	cout << "EC327: Introduction to Software Engineering" << endl << "Fall 2014" << endl << "Programming Assignment 4" << endl;

	Model model;
	View view;
	Sharknado sharkNATO; //Haha get it??
	
	model.show_status();
	model.display(view);

	char command;

	while(true)
	{
		cout << "Enter Command: ";
		cin >> command;

		try
		{
			switch(command)
			{
				case 's':
					do_swim_command(model);
					model.display(view);
				break;

				case 'e':
					do_eat_command(model);
					model.display(view);
				break;

				case 'f':
					do_float_command(model);
					model.display(view);
				break;

				case 'z':
					do_zoom_command(model);
					model.display(view);
				break;

				case 'g':
					do_go_command(model);
					sharkNATO.destroyShit(model);
					model.display(view);
				break;

				case 'r':
					do_run_command(model);
					sharkNATO.destroyShit(model);
					model.display(view);
				break;

				case 'a':
					do_attack_command(model);
					model.display(view);
				break;

				case 'n':
					handle_new_command(model);
					model.display(view);
				break;

				case 'q':
					cout << "Terminating Program" << endl;
					return 0;
				break;
			}
		}
		catch (InvalidInput& except) 
		{
		 cout << "Invalid input - " << except.msg_ptr << endl;
		 cin.clear();
		 cin.ignore(3,'\n');
		}
	}
	return 0;
}
