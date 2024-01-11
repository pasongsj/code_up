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
	// 0. �Է� �ޱ�
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

	// 1. ��� ��û�� ������ �� �ִ� ��쿡�� ��û�� �ݾ��� �״�� �����Ѵ�.
	if (sum < m)
	{
		return max;
	}

	// 2. ��� ��û�� ������ �� ���� ��쿡�� Ư���� ���� ���Ѿ��� ����Ͽ� �� �̻��� �����û���� ��� ���Ѿ��� �����Ѵ�. 
	// ���Ѿ� ������ �����û�� ���ؼ��� ��û�� �ݾ��� �״�� �����Ѵ�. 
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
			answer = mid; //�ִ� ����
		}
	}
	std::cout << answer;
	return 0;
}