//���ڿ��� ���� ���ڿ��� �����ϰ� �ִ� ��쿡, ��� ���� ���ڿ��� �����ϰ� �ȴ�.���� ���ڿ��� ������� �̾� �ٿ� ���ο� ���ڿ��� �����.
//���� ���� ���ڿ��� ���� ���ڿ��� ���ԵǾ� ���� ���� �ִ�.
//������ ���� ���ڿ��� ���ڿ��� ���� ������ ��ӵȴ�.

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