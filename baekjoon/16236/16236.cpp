#include <iostream>
#include <vector>
#include <queue>

int bfs(int r, int c, int nx, int ny, int cur_size, int cnt, const std::vector<std::vector<int>>&arr)
{
	if (r == nx && c == ny)
	{
		return cnt;
	}
}

int main()
{
	int n;
	std::cin >> n;
	std::vector<std::vector<int>> arr;
	arr.resize(n);
	int r = 0, c = 0;
	int m = 0;
	for (int i = 0;i < n;++i)
	{
		arr[i].resize(n);
		for (int j = 0;j < n;++j)
		{
			std::cin >> arr[i][j];
			if (arr[i][j] == 9)
			{
				r = i;
				c = j;
				arr[i][j] = 0;
			}
			else if (arr[i][j] != 0)
			{
				m++;
			}
		}
	}

	int cursize = 2;
	int eatcnt = 0;
	int ans = 0;
	while (m > 0)
	{
		int nx = r, ny = c;
		int range = 401;
		bool Eaten = false;
		for (int i = 0;i < n;++i)
		{
			for (int j = 0;j < n;++j)
			{

				if (0 != arr[i][j] && arr[i][j] < cursize)
				{
					int curdiff = abs(i - r) + abs(j - c);
					if (curdiff < range)
					{
						nx = i;
						ny = j;
						range = curdiff;
						Eaten = true;

					}
					else if (curdiff == range)
					{
						if (i<nx || i == nx && j<ny)
						{
							nx = i;
							ny = j;
							range = curdiff;
							Eaten = true;
						}
					}
				}
			}
		}
		if (true == Eaten)
		{
			arr[nx][ny] = 0;

			//ans += abs(nx - r) + abs(ny - c); // 최단거리 만들기
			ans += bfs(r, c, nx, ny, 0, arr);


			r = nx;
			c = ny;
			m--;
			eatcnt++;
			if (eatcnt == cursize)
			{
				cursize++;
				eatcnt = 0;
			}
		}
		else
		{
			break;
		}
	}
	std::cout << ans;
	return 0;
}