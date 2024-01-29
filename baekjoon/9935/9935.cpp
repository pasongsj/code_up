//���ڿ��� ���� ���ڿ��� �����ϰ� �ִ� ��쿡, ��� ���� ���ڿ��� �����ϰ� �ȴ�.���� ���ڿ��� ������� �̾� �ٿ� ���ο� ���ڿ��� �����.
//���� ���� ���ڿ��� ���� ���ڿ��� ���ԵǾ� ���� ���� �ִ�.
//������ ���� ���ڿ��� ���ڿ��� ���� ������ ��ӵȴ�.

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