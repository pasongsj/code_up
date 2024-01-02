#include <iostream>
#include <vector>
int main()
{
	int T,N;
	std::cin >> T;
	std::vector<int> arr;
	std::vector<int> answerVec;
	arr.resize(6);
	while(T--)
	{
		std::cin >> N;
		int feed = 0;
		int ans = 1;
		for (int i = 0; i < 6; ++i)
		{
			std::cin >> arr[i];
			feed += arr[i];
		}
		while (N >= feed)
		{
			feed *= 4;
			ans++;
		}
		answerVec.push_back(ans);
	}
	for (int a : answerVec)
	{
		std::cout << a << '\n';
	}

	return 0;
}