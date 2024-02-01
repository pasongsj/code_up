//문자열이 폭발 문자열을 포함하고 있는 경우에, 모든 폭발 문자열이 폭발하게 된다.남은 문자열을 순서대로 이어 붙여 새로운 문자열을 만든다.
//새로 생긴 문자열에 폭발 문자열이 포함되어 있을 수도 있다.
//폭발은 폭발 문자열이 문자열에 없을 때까지 계속된다.

#include <iostream>
#include <string>
#include <vector>

int main()
{
	std::string str, bomb;
	std::cin >> str >> bomb;

	std::vector<char> strvec;
	
	for (int i = 0; i < str.size(); ++i)
	{
		strvec.push_back(str[i]);
		if (str[i] == bomb.back())
		{
			bool is_same = true;
			for (int j = 1; j <= bomb.size(); ++j)
			{
				if (strvec.size() - j >= 0 && strvec[strvec.size() - j] == bomb[bomb.size() - j])
				{
					continue;
				}
				is_same = false;
				break;
			}
			if (true == is_same)
			{
				for (int j = 0; j < bomb.size(); ++j)
				{
					strvec.pop_back();
				}
			}
		}
	}
	if (0 == strvec.size())
	{
		std::cout<<"FRULA";
	}
	else
	{
		for (char _a : strvec)
		{
			std::cout << _a;
		}
	}
	return 0;
}