#include <iostream>
#include <vector>
#include <string>
int main()
{
	int a, b;
	std::cin >> a >> b;
	std::vector<int> dp;
	dp.resize(b + 1);
	for (int i = 1; i <= b; ++i)
	{
		std::string stri = std::to_string(i);
		dp[i] = dp[i - 1] % 20150523;
		if (i % 3 == 0 || std::string::npos != stri.find('3') || std::string::npos != stri.find('6') || std::string::npos != stri.find('9'))
		{
			dp[i]++;
		}
	}
	int answer = (dp[b] - dp[a - 1]) % 20150523;
	if (answer < 0)
	{
		answer += 20150523;
	}
	std::cout << answer;
	return 0;
}