#include <iostream>
#include <vector>

int main()
{
	int n;
	std::cin >> n;
	std::vector<int> arr;
	std::vector<int> score;
	std::vector<int> cnt;
	arr.resize(n + 1);
	score.resize(n + 1);
	cnt.resize(n + 1);
	for (int i = 1;i <= n;++i)
	{
		std::cin >> arr[i];
		if (i == 1)
		{
			score[i] = arr[i];
			cnt[i] = 1;
			continue;
		}

		if (cnt[i - 1] == 2)
		{
			if (score[i - 2] >= score[i - 3] + arr[i - 1])
			{
				score[i] = score[i - 2] + arr[i];
				cnt[i] = 1;
			}
			else
			{
				score[i] = score[i - 3] + arr[i - 1] + arr[i];
				cnt[i] = 2;
			}
		}
		else
		{
			if (score[i - 1] > score[i - 2])
			{
				score[i] = score[i - 1] + arr[i];
				cnt[i] = cnt[i - 1] + 1;
			}
			else
			{
				score[i] = score[i - 2] + arr[i];
				cnt[i] = 1;
			}
		}
	}


	std::cout << score[n];
	return 0;
}