#include "heap.h"
#include <iostream>


int main()
{
	heap* curheap = new heap();

	curheap->push(7);
	curheap->push(6);
	curheap->push(0);
	curheap->push(8);
	curheap->push(78);
	curheap->push(68);
	curheap->push(48);
	curheap->push(48);

	while (!curheap->empty())
	{
		std::cout << curheap->top() << ' ';
		curheap->pop();
	}

	return 0;
}