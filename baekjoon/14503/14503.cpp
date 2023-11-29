#include <iostream>
#include <vector>


bool in_range(int x, int y, int n, int m)
{
	return 0 <= x && x < n && 0 <= y && y < m;
}

int main()
{
	const int dirx[4] = {-1,0,1,0} ;
	const int diry[4] = {0,1,0,-1} ;
	
	int n,m,r,c,cur_dir;
	std::cin >> n >> m >> r >> c >> cur_dir;
	std::vector<std::vector<int>> arr;
	// 입력받음
	arr.resize(n);
	for (int i = 0;i < n;++i)
	{
		arr[i].resize(m);
		for (int j = 0;j < m;++j)
		{
			std::cin >> arr[i][j];
		}
	}

	int ans = 0;
	while (true)
	{
		if (0 == arr[r][c]) // 현재 칸이 아직 청소되지 않은 경우, 현재 칸을 청소한다.
		{
			ans++;
			arr[r][c] = 2;
		}

		bool canclean = false;
		int tmpdir = cur_dir;
		for (int i = 0;i < 4;++i)
		{
			tmpdir = (tmpdir + 3) % 4; // 반시계 방향으로 회전
			int nx = r + dirx[tmpdir];
			int ny = c + diry[tmpdir];
			if (true == in_range(nx, ny, n, m) && 0 == arr[nx][ny]) // 청소되지 않은 빈 칸이 있는 경우
			{
				r = nx;
				c = ny;
				canclean = true;
				cur_dir = tmpdir;
				break;
			}
		}
		if (true == canclean)
		{
			continue;
		}
		else // 청소되지 않은 빈 칸이 없는 경우
		{
			int nx = r - dirx[cur_dir];
			int ny = c - diry[cur_dir];
			if (true == in_range(nx, ny, n, m) && 1 != arr[nx][ny]) // 후진할 수 있다면 
			{
				r = nx;
				c = ny;
				continue;
			}
			break; // 후진할 수 없다면 작동을 멈춘다.
		}
	}
	std::cout << ans;
	return 0;
}


