//문자열이 폭발 문자열을 포함하고 있는 경우에, 모든 폭발 문자열이 폭발하게 된다.남은 문자열을 순서대로 이어 붙여 새로운 문자열을 만든다.
//새로 생긴 문자열에 폭발 문자열이 포함되어 있을 수도 있다.
//폭발은 폭발 문자열이 문자열에 없을 때까지 계속된다.

#include <iostream>
#include <string>
#include <list>
int main()
{
	std::string str, bomb;
	std::cin >> str >> bomb;


	int bomb_len = bomb.size();
	while (true)
	{
		bool is_bomb = false;
		std::list<int> bomb_index;
		int cur_index = 0;

		while (true)
		{
			if (std::string::npos == str.find(bomb, cur_index))
			{
				break;
			}
			cur_index = str.find(bomb, cur_index);
			bomb_index.push_back(cur_index);
			cur_index += bomb_len;
			is_bomb = true;
		}

		std::string tmpstr = "";
		for (int i = 0; i < str.size(); ++i)
		{
			if (false == bomb_index.empty() && i == bomb_index.front())
			{
				bomb_index.pop_front();
				i += bomb_len-1;
				continue;
			}
			tmpstr += str[i];
		}

		str = tmpstr;

		if (false == is_bomb)
		{
			break;
		}
	}
	if (0 == str.length())
	{
		str = "FRULA";
	}
	std::cout << str;
	return 0;
}