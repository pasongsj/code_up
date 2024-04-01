#include <iostream>
#include <climits>

int GetDiv5Cnt(int _num)
{
	int div5 = 5;
	int cnt = 0;
	while (true)
	{
		if (_num < div5)
		{
			break;
		}
		cnt += (_num / div5);
		div5 *= 5; // 5의 배수마다 확인
	}
	return cnt;
}

int GetBinarySearch(int num)
{
	int left = 1, right = INT_MAX;
	int answer = -1;

	while (left <= right)
	{
		int mid = (left + right) / 2;
 		int cnt = GetDiv5Cnt(mid);

		if (num <= cnt)
		{
			answer = mid;
			right = mid - 1;
		}
		else
		{
			left = mid + 1;
		}
	}
	return answer;
}

int main()
{
	int m;
	std::cin >> m;
	int ans = 5 * m;
	int answer = GetBinarySearch(m);
	if (GetDiv5Cnt(answer) == m)
	{
		std::cout << answer;
	}
	else
	{
		std::cout << -1;
	}


	return 0;
}