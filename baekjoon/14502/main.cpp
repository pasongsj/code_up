#include <iostream>
#include <vector>
#include <climits>

#include <queue>

bool in_range(int x, int y, int n, int m)
{
	return 0 <= x && x < n && 0 <= y && y < m;
}

int main()
{
	int n, m;
	std::cin >> n >> m;
	std::vector<std::vector<int>> arr;
	std::vector<std::vector<int>> Weight;

	std::vector<std::pair<int, int>> viruses;
	std::vector<std::pair<int, int>> CanWall;

	arr.resize(n);
	Weight.resize(n);
	int cnt = 0;

	for (int i = 0;i < n;++i)
	{
		for (int j = 0;j < m;++j)
		{
			int tmp;
			std::cin >> tmp;
			arr[i].push_back(tmp);
			Weight[i].push_back(INT_MAX);
			if (tmp == 2)
			{
				viruses.push_back(std::make_pair(i, j));
			}
			else if (tmp == 1)
			{
				CanWall.push_back(std::make_pair(i, j));
				cnt++;
			}
		}
	}


	return 0;
}