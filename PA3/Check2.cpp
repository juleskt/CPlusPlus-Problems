#include "CartPoint.h"
#include "CartVector.h"
#include "GameObject.h"
#include "CoralReef.h"
#include "Cave.h"
#include "Fish.h"
#include "Model.h"
#include "GameCommand.h"
#include "View.h"
#include <iostream>

//char command;
using namespace std;

int main()
{
	cout << "EC327: Introduction to Software Engineering" << endl << "Fall 2014" << endl << "Programming Assignment 3" << endl;

	Model model;
	View view;
	
	model.show_status();
	model.display(view);

	char command;

	while(true)
	{
		cout << "Enter Command: ";
		cin >> command;

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
				model.display(view);
			break;

			case 'r':
				do_run_command(model);
			break;

			case 'q':
				cout << "Terminating Program" << endl;
				return 0;
			break;
		}
	}
	return 0;
}