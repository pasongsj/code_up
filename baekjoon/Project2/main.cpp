#include <iostream>

int get_apple(int& s, int& e, int cur)
{
	if (s <= cur && cur <= e)
	{
		return 0;
	}
	int move = 0;
	if (cur - e > 0)
	{
		move = cur - e;
		s += move;
		e += move;
	}
	else
	{
		move = s - cur;
		s -= move;
		e -= move;
	}
	return move;
}
int main()
{
	int answer = 0;
	int n, m, j ;
	std::cin >> n >> m >> j;
	int s = 1;
	int e = m;
	for (int i = 0;i < j;++i)
	{
		int tmp;
		std::cin >> tmp;
		answer += get_apple(s, e, tmp);
	}

	std::cout << answer;
	return 0;
}