#include <iostream>
#include <queue>
#include <vector>

int main()
{
	int n;
	std::cin >> n;


	std::priority_queue<int> lower;
	std::priority_queue<int> upper;
	std::vector<int> answer;

	for (int i = 0; i < n; ++i)
	{
		int tmp;
		std::cin >> tmp;
		if (true == lower.empty())
		{
			lower.push(tmp);
		}
		else if (lower.size() <= upper.size())
		{
			if(tmp<-upper.top())
			{
				lower.push(tmp);
			}
			else
			{
				lower.push(-upper.top());
				upper.pop();
				upper.push(-tmp);
			}
		}
		else
		{
			if (tmp < lower.top())
			{
				upper.push(-lower.top());
				lower.pop();
				lower.push(tmp);
			}
			else
			{
				upper.push(-tmp);
			}
		}

		answer.push_back(lower.top());
	}
	for (int num : answer)
	{
		std::cout << num << '\n';
	}

	return 0;
}