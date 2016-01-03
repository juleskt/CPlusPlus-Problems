#ifndef SHARKNADO_H
#define SHARKNADO_H

#include "Fish.h"
#include <list>
#include "Model.h"

class Sharknado
{
	public:
		Sharknado();
		~Sharknado();
		
		void destroyShit(Model&);

		list<Fish*> livesClaimed;
		list<Fish*> totalLivesClaimed;
};

#endif