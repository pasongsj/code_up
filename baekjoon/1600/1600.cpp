#include <iostream>
#include <vector>
#include <map>
int main()
{
	int k;
	std::cin >> k;
	int w, h;
	std::cin >> w >> h;
	std::vector<std::vector<int>> arr;

	std::vector<std::vector<std::map<int,int>>> dp; //i, j,  map(move, remain k)

	arr.resize(w);
	dp.resize(w);
	for (int i = 0; i < w; ++i)
	{
		arr[i].resize(h);
		dp[i].resize(h);
		for (int j = 0; j < h; ++j)
		{
			std::cin >> arr[i][j];
		}
	}

	int cx = 0, cy = 0;

	dp[cx][cy][k] = 0;
	return 0;
}