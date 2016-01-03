#ifndef VIEW_H
#define VIEW_H

#include "GameObject.h"
#include "CartPoint.h"
#include <iomanip>

const int view_maxsize = 20;

class View
{
	public:
		View();
		void clear();
		void plot(GameObject*);
		void draw();
	private:
		int size;
		double scale;
		CartPoint origin;
		char grid[view_maxsize][view_maxsize][2];
		bool get_subscripts(int&, int&,CartPoint);
};

#endif 