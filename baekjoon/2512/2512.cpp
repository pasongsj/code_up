#include <iostream>
#include <vector>
std::vector<int> regions;
int n,m;

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
	// 0. 입력 받기
	int max_num = 0;
	std::cin >> n;
	for (auto i = 0; i < n; i++) {
		int x;
		std::cin >> x;
		regions.push_back(x);
		max_num = max_num > x ? max_num : x;
	}
	std::cin >> m;


	// 1. 모든 요청이 배정될 수 있는 경우에는 요청한 금액을 그대로 배정한다.

	// 2. 모든 요청이 배정될 수 없는 경우에는 특정한 정수 상한액을 계산하여 그 이상인 예산요청에는 모두 상한액을 배정한다. 
	// 상한액 이하의 예산요청에 대해서는 요청한 금액을 그대로 배정한다. 
	int left = 0, right = max_num;
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