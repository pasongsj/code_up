#include <iostream>
#include <vector>
#include <string>


int main()
{
	int n;
	std::cin >> n;
	std::vector<std::vector<int>> arr_dp;
	arr_dp.resize(10);

	// x���� ���� ����
	for (int i = 0; i < 10; ++i)
	{
		// y���� ���� ����
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

			// ���� i+1�ڸ������� ���� j��
			if (cur_cnt >= n)
			{
				int len_ = i-1;
				int cur_first = j-1;
				int remain = cur_cnt - n;
				std::string res = std::to_string(j);

				// 1�� �ڸ� �� ���� ����
				while (len_ >= 0)
				{
					// �� �� �ִ� ���� �ڸ�
					for (int k = cur_first; k >= 0; k--)
					{
						if (remain - arr_dp[len_][k] < 0)
						{
							res += std::to_string(k);
							cur_first = k - 1;
							len_--;
							break;
						}
						// 1���ڸ� ��  0 ����ó��
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