#include "Sharknado.h"

Sharknado::Sharknado()
{
	cout << "Sharknado constructed" << endl;
}

Sharknado::~Sharknado()
{	
	cout << "----------The History of Sharknado's Wrath----------" << endl;
	for(list<Fish *>::iterator it = totalLivesClaimed.begin(); it != totalLivesClaimed.end(); it++)
		{
			cout << (*it)->get_display_code() << (*it)->get_id() << endl;
			//delete *it;
 		}
 	cout << "----------------------------------------------------" << endl;

	cout << "Sharknado deconstructed" << endl;
}

void Sharknado::destroyShit(Model& model)
{
	if(model.getTime() % 15 == 0 && model.getTime() != 0)
	{
		cout << "The Sharknado is upon us! " << endl;
		cout << "----------The Sharknado Claimed----------" << endl;

		for(list<Fish *>::iterator it = model.fish_ptrs.begin(); it != model.fish_ptrs.end(); it++)
		{
			if(!(*it)->is_hidden())
			 {
			 	livesClaimed.push_back(*it);
			 	totalLivesClaimed.push_back(*it);
			 	//model.deletePtr(*it);
				model.active_ptrs.remove(dynamic_cast<GameObject*>(*it));
				model.object_ptrs.remove(dynamic_cast<GameObject*>(*it));

				for(list<Fish *>::iterator it = model.fish_ptrs.end(); it != model.fish_ptrs.begin(); it++)
				{
					model.fish_ptrs.remove(*it);
			 	}
			 }
		}

		if(livesClaimed.size() != 0)
		{
			int count = 1;
			
			for(list<Fish *>::iterator it = livesClaimed.begin(); it != livesClaimed.end(); it++)
			{
				cout << "(" << count << ")" << (*it)->get_display_code() << (*it)->get_id() << endl;
				count++;
	 		}
	 	}
	 	
	 	livesClaimed.clear();
	 	cout << "-----------------------------------------" << endl;
	}

	if((model.getTime()+5) % 15 == 0)
	{
		cout << "The Sharknado is coming!" << endl;
	}
}