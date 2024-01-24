#include <iostream>
#include <vector>
#include <string>


int main()
{
	int n;
	std::cin >> n;
	std::vector<std::vector<int>> arr_dp;
	arr_dp.resize(10);

	// x축은 숫자 길이
	for (int i = 0; i < 10; ++i)
	{
		// y축은 시작 숫자
		arr_dp[i].resize(10);
		for (int j = 0; j < 10; ++j)
		{
			if (0 == i)
			{
				arr_dp[i][j] = 1;
				continue;
			}
			if (j == 0)
			{
				continue;
			}
			arr_dp[i][j] = arr_dp[i][j - 1] + arr_dp[i - 1][j - 1];
		}
	}

	arr_dp[0][0] = 0;

	int cur_cnt = 0;
	for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			cur_cnt += arr_dp[i][j];

			// 현재 i+1자리수에는 숫자 j임
			if (cur_cnt >= n)
			{
				int len_ = i-1;
				int cur_first = j-1;
				int remain = cur_cnt - n;
				std::string res = std::to_string(j);

				// 1의 자리 수 까지 결정
				while (len_ >= 0)
				{
					// 올 수 있는 다음 자리
					for (int k = cur_first; k >= 0; k--)
					{
						if (remain - arr_dp[len_][k] < 0)
						{
							res += std::to_string(k);
							cur_first = k - 1;
							len_--;
							break;
						}
						// 1의자리 수  0 예외처리
						else if (len_ == 0 && remain == 0)
						{
							res += std::to_string(0);
							len_--;
							break;
						}
						remain -= arr_dp[len_][k];
					}
				}
				std::cout << res;
				return 0;
			}
		}
	}
	std::cout << -1;

	int a = 0;
	return 0;
}