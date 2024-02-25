#include <iostream>
#include <vector>
#include <set>

std::vector<std::vector<int>> arr;
std::set<int> start_team;
std::set<int> link_team;

int res = 1E+9;;


int getdiff()
{
	int start = 0;
	int link = 0;
	{
		std::set<int>::iterator it = start_team.begin();
		std::set<int>::iterator endit = start_team.end();
		for (; it != endit; ++it)
		{
			std::set<int>::iterator nextit = it;
			nextit++;
			for (; nextit != endit; ++nextit)
			{
				start += arr[*it][*nextit];
				start += arr[*nextit][*it];
			}
		}
	}


	{
		std::set<int>::iterator it = link_team.begin();
		std::set<int>::iterator endit = link_team.end();
		for (; it != endit; ++it)
		{
			std::set<int>::iterator nextit = it;
			nextit++;
			for (; nextit != endit; ++nextit)
			{
				link += arr[*it][*nextit];
				link += arr[*nextit][*it];
			}
		}
	}
	return abs(start - link);
}

void getcomb(int index, int max)
{
	if (start_team.size() == max / 2)
	{
		for (int i = 0; i < max; ++i)
		{
			if (start_team.end() == start_team.find(i))
			{
				link_team.insert(i);
			}
		}
		int diff = getdiff();
		res = res > diff ? diff : res;
		link_team.clear();
		return;
	}
	for (; index < max; ++index)
	{
		start_team.insert(index);
		getcomb(index + 1, max);
		start_team.erase(index);
	}
}

int main()
{
	int n;
	std::cin >> n;
	arr.resize(n);
	for (int i = 0; i < n; ++i)
	{
		arr[i].resize(n);
		for (int j = 0; j < n; ++j)
		{
			std::cin >> arr[i][j];
		}
	}


	getcomb(0, n);

	std::cout << res;
	return 0;
}