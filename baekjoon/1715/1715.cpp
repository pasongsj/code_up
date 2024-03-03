#include <iostream>
#include <queue>

int main()
{
	std::priority_queue<int> q;
	int n;
	std::cin >> n;
	for (int i = 0; i < n; ++i)
	{
		int tmp;
		std::cin >> tmp;
		q.push(-tmp);
	}
	int ans = 0;
	while (q.size() > 1)
	{
		int a, b;
		a = q.top();
		q.pop();
		b = q.top();
		q.pop();
		ans += a + b;
		q.push(a + b);
	}
	std::cout << -ans;
	return 0;

}