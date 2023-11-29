#include <iostream>
#include <vector>
#include <queue>


int fifo(const int m, const int index)
{
	std::queue<std::pair<int,int>> q;
	std::priority_queue<int> topnum;
	for (int i = 0;i < m;++i)
	{
		int cur;
		std::cin >> cur;
		if (i == index)
		{
			q.push(std::make_pair(cur, -1));
		}
		else
		{
			q.push(std::make_pair(cur, 0));
		}
		topnum.push(cur);
	}

	int result = 0;
	while (true)
	{
		std::pair<int, int> curnum = q.front();
		if (topnum.top() > curnum.first)
		{
			q.pop();
			q.push(curnum);
		}
		else if (topnum.top() == curnum.first)
		{
			result++;
			topnum.pop();
			q.pop();
			if (curnum.second == -1)
			{
				break;
			}
		}
	}
	return result;
}

int main()
{
	int n;
	std::cin >> n;
	std::vector<int> answer;

	for (int i = 0;i < n;++i)
	{
		int m, index;
		std::cin >> m >> index;
		answer.push_back(fifo(m, index));
	}

	for (int i = 0;i < n;++i)
	{
		std::cout << answer[i] << '\n';
	}

	return 0;
}