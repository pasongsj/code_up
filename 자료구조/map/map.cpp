#include "map.h"
#include <iostream>




int main()
{
	map* curmap = new map();
	curmap->insert({ 1,2 });
	curmap->insert({ 3,5 });
	curmap->insert({ 8,7 });
	curmap->insert({ 2,4 });
	curmap->insert({ 1,1 });

	//curmap->erase(1);
	map::iterator it = curmap->begin();
	map::iterator endit = curmap->end();

	for (; it != endit; ++it)
	{
		std::cout << it->key << ',' << it->value << '\n';
	}

	return 0;
}