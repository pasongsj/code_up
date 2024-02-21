#include <iostream>
#include <vector>
#include <algorithm>
#include <crtdbg.h>
std::vector<int> arr;


class SegTree
{
public:
	int start;
	int end;
	int max;
	int min;
	static std::vector<SegTree*> AllTree;
};

void MakeTree(int start, int end, int nodenumber)
{

}

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	int n, m;
	std::cin >> n >> m;
	
	arr.resize(n);
	for (int i = 0; i < n; ++i)
	{
		std::cin >> arr[i];
	}

	return 0;
}