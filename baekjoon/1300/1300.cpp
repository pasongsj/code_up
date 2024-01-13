#include <iostream>
#include <algorithm>

int main()
{
	int n, m;
	std::cin >> n >> m;
	int left = 0, right = m;
	while (left <= right)
	{
		int mid = (left + right) / 2;
		
		int cnt = 0;
		for (int i = 1; i <= n; i++)
		{
			cnt += std::min(n, (mid / i));
		}

		if (cnt >= m)
		{
			right = mid - 1;
		}
		else
		{

			left = mid + 1;
		}
	}
	std::cout << left;

}

//	1	2	3	4	5
//	2	4	6	8	10
//	3	6	9	12	15
//	4	8	12	16	20
//	5	10	15	20	28

// 1 2 2 3 3 4 4 4 5 5 6	6	6	6 
// 0 1 2 3 4 5 6 7 8 9 10	11	12	13