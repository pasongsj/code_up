#include <iostream>
#include <vector>
std::vector<int> regions;
int n;

long long CalSum(int num)
{
	long long sum = 0;
	for (int i = 0; i < n; ++i)
	{
		sum += (num > regions[i] ? regions[i] : num);
	}
	return sum;
}

int main()
{
	int m;
	// 0. 입력 받기
	std::cin >> n;
	regions.resize(n);

	int sum = 0, max = 0;
	for (int i = 0; i < n; ++i)
	{
		std::cin >> regions[i];
		sum += regions[i];
		max = max > regions[i] ? max : regions[i];
	}
	std::cin >> m;

	// 1. 모든 요청이 배정될 수 있는 경우에는 요청한 금액을 그대로 배정한다.
	if (sum < m)
	{
		return max;
	}

	// 2. 모든 요청이 배정될 수 없는 경우에는 특정한 정수 상한액을 계산하여 그 이상인 예산요청에는 모두 상한액을 배정한다. 
	// 상한액 이하의 예산요청에 대해서는 요청한 금액을 그대로 배정한다. 
	int left = 0, right = max;
	int answer = 0;
	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (CalSum(mid) > m)
		{
			right = mid - 1;
		}
		else
		{
			left = mid + 1;
			answer = mid; //최댓값 갱신
		}
	}
	std::cout << answer;
	return 0;
}