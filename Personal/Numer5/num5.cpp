#include <iostream>
#include <vector>


int main()
{

	std::vector<int> hone = {-1,0,0,1,1};
	std::vector<int> upperdp;
	std::vector<int> botdp;

	int n = hone.size();
	upperdp.resize(n);
	botdp.resize(n);
	upperdp[0] = 1;
	botdp[0] = 1;


	for (int i = 1; i < n; ++i)
	{
		if (0 == hone[i]) // 
		{
			upperdp[i] = upperdp[i - 1] + botdp[i - 1];
			botdp[i] = upperdp[i - 1] + botdp[i - 1] * 2;
		}
		else //
		{
			upperdp[i] = upperdp[i - 1] + botdp[i - 1] * 2;
			botdp[i] = upperdp[i - 1] + botdp[i - 1] * 3;
		}
	}



	///

	std::vector<int> dp;

	dp.resize(n);
	dp[0] = 1;
	if (hone[1] == 1)
	{
		dp[1] = 4;
	}
	else
	{
		dp[1] = 3;
	}
	for (int i = 2; i < n; ++i)
	{
		if (hone[i] == 1) 
		{
			dp[i] = 4 * dp[i - 1] - dp[i - 2];
		}

		else
		{
			dp[i] = 3 * dp[i - 1] - dp[i - 2];
		}
	}

	std::cout<<botdp.back()<<' '<<dp.back();
	return 0;
}