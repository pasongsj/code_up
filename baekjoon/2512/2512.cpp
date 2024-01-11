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
	// 0. �Է� �ޱ�
	int max_num = 0;
	std::cin >> n;
	for (auto i = 0; i < n; i++) {
		int x;
		std::cin >> x;
		regions.push_back(x);
		max_num = max_num > x ? max_num : x;
	}
	std::cin >> m;


	// 1. ��� ��û�� ������ �� �ִ� ��쿡�� ��û�� �ݾ��� �״�� �����Ѵ�.

	// 2. ��� ��û�� ������ �� ���� ��쿡�� Ư���� ���� ���Ѿ��� ����Ͽ� �� �̻��� �����û���� ��� ���Ѿ��� �����Ѵ�. 
	// ���Ѿ� ������ �����û�� ���ؼ��� ��û�� �ݾ��� �״�� �����Ѵ�. 
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
			answer = mid; //�ִ� ����
		}
	}
	std::cout << answer;
	return 0;
}