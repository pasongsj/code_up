#include <iostream>
#include <vector>
#include <climits>
#include <map>

int main()
{
	int goal, city_cnt;
	std::cin >> goal >> city_cnt;
	std::map<int, int> dp;

	std::vector<std::pair<int, int>> promotion;
	
	for (int i = 0;i < city_cnt;++i)
	{
		int price, custom;
		std::cin >> price >> custom;
		promotion.push_back(std::make_pair(price,custom));
		if (dp.end() == dp.find(custom))
		{
			dp[custom] = price;
		}
		else
		{
			dp[custom] = dp[custom] > price ? price : dp[custom];
		}
	}

	dp[0] = 0;
	for (int i = 1;i <= goal;++i)
	{
		if (dp.end() == dp.find(i)) 
{
			continue;
		}
		for (const std::pair<int, int>& prom : promotion)
		{
			int cur_goal = i + prom.second;
			if (dp.end() != dp.find(cur_goal) || dp[cur_goal] != 0)
			{
				dp[i + prom.second] = (dp[i] + prom.first > dp[i + prom.second] ? dp[i + prom.second] : dp[i] + prom.first);
			}
			else
			{
				dp[i + prom.second] = dp[i] + prom.first;
			}
		}
		int a = 0;

	}

	auto it = dp.lower_bound(goal);
	int answer = it->second;
	for (;it != dp.end();it++)
	{
		answer = std::min(answer, it->second);
	}
	std::cout << answer;	

	return 0;
}