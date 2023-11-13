#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

bool in_range(int x, int y, int n, int m)
{
	return 0 <= x && x < n && 0 <= y && y < m;
}


int search(int x, int y, std::vector<std::vector<int>>& arr)
{
	int nx[4] = { -1,1,0,0 };
	int ny[4] = { 0,0,-1,1 };
	std::queue<std::pair<int,int>> q;
	q.push(std::make_pair(x, y));
	arr[y][x]++;
	int ans = 0;
	while (!q.empty())
	{
		std::pair<int, int> cur = q.front();
		q.pop();
		ans++;
		for (int i = 0;i < 4;++i)
		{
			int nextX = cur.first + nx[i];
			int nextY = cur.second + ny[i];
			if (true == in_range(nextX, nextY,arr[0].size(), arr.size()) && arr[nextY][nextX] == 0)
			{
				q.push(std::make_pair(nextX, nextY));
				arr[nextY][nextX]++;
			}
		}
	}
	return ans;
}

int main()
{
	int n, m, k;
	std::cin >> m >> n >> k; // y - m, x - n

	std::vector<std::vector<int>> arr;
	arr.resize(m);
	for (int i = 0;i < m; ++i)
	{
		arr[i].resize(n);
	}

	for (int i = 0;i < k;++i)
	{
		int x1, y1, x2, y2;
		std::cin >> x1 >> y1 >> x2 >> y2;
		for (;y1 < y2;y1++)
		{
			int x = x1;
			for (;x < x2;x++)
			{
				arr[y1][x]++;
			}
		}
	}

	int a = 0;
	std::vector<int> answer;
	for (int j = 0;j < m;++j)
	{
			for (int i = 0;i < n;++i)
		{
			if (arr[j][i] == 0)
			{
				int a = search(i, j, arr);
				answer.push_back(a);
			}
		}
	}

	sort(answer.begin(), answer.end());
	std::cout << answer.size() << std::endl;
	for (int ans : answer)
	{
		std::cout << ans << ' ';
	}
	return 0;

}