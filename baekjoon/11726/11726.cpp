#include <iostream>
#include <vector>
int main()
{
	int n;
	std::cin >> n;
	std::vector<int> last1;
	std::vector<int> last2;
	last1.resize(n + 2);
	last2.resize(n + 2);
	last1[1] = 1;
	last2[1] = 0;
	last1[2] = 1;
	last2[2] = 1;
	for (int i = 3;i <= n;++i)
	{
		last1[i] = (last1[i - 1] + last2[i - 1])% 10007;
		last2[i] = (last1[i - 2] + last2[i - 2])% 10007;
	}
	std::cout << (last1[n] + last2[n])%10007;
	return 0;
}
// 111
// 21
// 12