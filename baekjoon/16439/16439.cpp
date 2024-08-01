#include <iostream>
#include <vector>
#include <algorithm>

int GetPreference(const std::vector<int>& pick, const std::vector<std::vector<int>>& prefvec)
{
	int ans = 0;
	int n = prefvec.size();
	int m = prefvec[0].size();
	std::vector<int> prefer;
	prefer.resize(n);

	for (int i = 0; i < pick.size(); ++i)
	{
		if (1 == pick[i])
		{
			for (int j = 0; j < n; ++j)
			{
				prefer[j] = std::max(prefer[j], prefvec[j][i]);
			}
		}
	}

	for (int cnt : prefer)
	{
		ans += cnt;
	}

	return ans;
}

int main()
{
	int n, m;
	std::vector<std::vector<int>> pref;

	std::cin >> n >> m;

	pref.resize(n);
	for (int i = 0; i < n; ++i)
	{
		pref[i].resize(m);
		for (int j = 0; j < m; ++j)
		{
			std::cin >> pref[i][j];
		}
	}

	std::vector<int> getcomb;
	getcomb.resize(m);
	getcomb[0] = 1;
	getcomb[1] = 1;
	getcomb[2] = 1;

	std::sort(getcomb.begin(), getcomb.end());
	int answer = 0;
	do {
		answer = std::max(answer, GetPreference(getcomb, pref));
	} while (std::next_permutation(getcomb.begin(), getcomb.end()));

	std::cout << answer;
	return 0;
}