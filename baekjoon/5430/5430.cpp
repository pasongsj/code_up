#include <iostream>
#include <queue>
#include <vector>
#include <string>

int main()
{

	int t, n;
	std::string p;
	std::vector<std::string> answer;

	std::cin >> t;

	for (int i = 0; i < t; ++i)
	{
		std::deque<int> arr;
		char tmp;
		bool IsReverse = false;
		bool IsError = false;
		std::cin >> p >> n >> tmp;
		for (int j=0;j<n;++j)
		{
			int inputnum;
			std::cin >> inputnum;
			arr.push_back(inputnum);
			std::cin >> tmp;
		}
		if (n == 0)
		{
			std::cin >> tmp;
		}
		for (char p_func : p)
		{
			if ('R' == p_func)
			{
				IsReverse = !IsReverse;
			}
			else if ('D' == p_func)
			{
				if (true == arr.empty())
				{
					IsError = true;
					//answer.push_back("error");
					// error
					break;
				}
				if (false == IsReverse)
				{
					arr.pop_front();
				}
				else
				{
					arr.pop_back();
				}
			}
		}

		if (arr.empty() && true == IsError)
		{
			answer.push_back("error");
			continue;
		}

		std::string ans = "[";
		while (!arr.empty())
		{
			if (true == IsReverse)
			{
				ans += std::to_string(arr.back());
				arr.pop_back();
			}
			else
			{
				ans += std::to_string(arr.front());
				arr.pop_front();
			}
			if (arr.empty())
			{
				break;
			}
			ans += ",";
		}
		ans += "]";
		answer.push_back(ans);
	}
		

	for (const std::string& _ans : answer)
	{
		std::cout << _ans << '\n';
	}


	return 0;


}