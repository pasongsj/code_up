#include <iostream>
#include <string>

bool Cal(int cnt, std::string& cur)
{

	const std::string strA = "AAAA";
	const std::string strB = "BB"; 

	if (cnt > 0)
	{
		if (cnt % 2 != 0)
		{
			return false;
		}
		else
		{
			while (cnt > 0)
			{
				if (cnt >= 4)
				{
					cur += strA;
					cnt -= 4;
				}
				else
				{
					cur += strB;
					cnt -= 2;
				}
			}
		}
	}
	return true;
}

int main()
{
	std::string input;
	std::cin >> input;
	std::string answer;


	int cnt = 0;
	for (char c : input)
	{
		if (c == '.')
		{
			if (false == Cal(cnt, answer))
			{
				std::cout << -1;
				return 0;
			}
			answer += '.';
			cnt = 0;
		}
		else
		{
			cnt++;
		}
	}
	if (false == Cal(cnt, answer))
	{
		std::cout << -1;
		return 0;
	}
	std::cout << answer;

	return 0;
}