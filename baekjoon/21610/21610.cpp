//1. 모든 구름이 di 방향으로 si칸 이동한다.
//2. 각 구름에서 비가 내려 구름이 있는 칸의 바구니에 저장된 물의 양이 1 증가한다.
//구름이 모두 사라진다.
//3. 2에서 물이 증가한 칸(r, c)에 물복사버그 마법을 시전한다.물복사버그 마법을 사용하면, 대각선 방향으로 거리가 1인 칸에 물이 있는 바구니의 수만큼(r, c)에 있는 바구니의 물이 양이 증가한다.
//이때는 이동과 다르게 경계를 넘어가는 칸은 대각선 방향으로 거리가 1인 칸이 아니다.
//예를 들어, (N, 2)에서 인접한 대각선 칸은(N - 1, 1), (N - 1, 3)이고, (N, N)에서 인접한 대각선 칸은(N - 1, N - 1)뿐이다.
//4. 바구니에 저장된 물의 양이 2 이상인 모든 칸에 구름이 생기고, 물의 양이 2 줄어든다.이때 구름이 생기는 칸은 3에서 구름이 사라진 칸이 아니어야 한다.

#include <iostream>
#include <vector>

int n;

std::vector<std::vector<int>> base_arr;
std::vector<std::vector<int>> tmp_arr;
std::vector<std::vector<int>> cloud_pos;
std::vector<std::vector<int>> tmp_cloud_pos;


void MakeClould()
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (2 <= base_arr[i][j] && 0 == cloud_pos[i][j])
			{
				tmp_cloud_pos[i][j] = 1;
				base_arr[i][j] -= 2;
			}
		}
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cloud_pos[i][j] = tmp_cloud_pos[i][j];
		}
	}

}

bool InRange(int x, int y)
{
	return 0 <= x && x < n && 0 <= y && y < n;
}


void MagicBug()
{

	const int dx[4] = {-1,1,1,-1};
	const int dy[4] = {-1,-1,1,1};
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			tmp_arr[i][j] = base_arr[i][j];
			if (cloud_pos[i][j] == 0)
			{
				continue;
			}
			int sum = 0;

			for (int k = 0; k < 4; ++k)
			{
				int nx = i + dx[k];
				int ny = j + dy[k];
				if (true == InRange(nx, ny) && 0 < base_arr[nx][ny])
				{
					sum++;
				}
			}
			tmp_arr[i][j] += sum;
		}
	}

	// cpy
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			base_arr[i][j] = tmp_arr[i][j];
		}
	}
}

// (N, 1), (N, 2), (N-1, 1), (N-1, 2)에 비구름이 생긴다
void InitCloud()
{
	cloud_pos[n - 1][0] = 1;
	cloud_pos[n - 1][1] = 1;
	cloud_pos[n - 2][0] = 1;
	cloud_pos[n - 2][1] = 1;
}

void ResetVec(std::vector<std::vector<int>>& _arr)
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			_arr[i][j] = 0;
		}
	}
}

void AddCouldToBase()
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (1 == cloud_pos[i][j])
			{
				base_arr[i][j]++;
			}
		}
	}
}

void MoveCloud(int dir, int mov)
{
	// move cloud
	const int dx[9] = { 0,0,-1,-1,-1,0,1,1,1 };
	const int dy[9] = { 0,-1,-1,0,1,1,1,0,-1 };
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			int nx = (i + mov * (dx[dir] + n)) % n;
			int ny = (j + mov * (dy[dir] + n)) % n;
			tmp_cloud_pos[nx][ny] = cloud_pos[i][j];
		}
	}

	// cpy
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cloud_pos[i][j] = tmp_cloud_pos[i][j];
		}
	}
}


int main()
{
	int m;

	std::cin >> n >> m;

	// resize
	base_arr.resize(n);
	tmp_arr.resize(n);
	cloud_pos.resize(n);
	tmp_cloud_pos.resize(n);
	for (int i = 0; i < n; ++i)
	{
		base_arr[i].resize(n);
		tmp_arr[i].resize(n);
		cloud_pos[i].resize(n);
		tmp_cloud_pos[i].resize(n);
		for (int j = 0; j < n; ++j)
		{
			std::cin >> base_arr[i][j];
		}
	}

	InitCloud();
	

	while (m--)
	{
		int d, s;
		std::cin >> d >> s;

		//1. 모든 구름이 di 방향으로 si칸 이동한다.
		MoveCloud(d, s);

		// 2. 각 구름에서 비가 내려 구름이 있는 칸의 바구니에 저장된 물의 양이 1 증가한다.

		AddCouldToBase();

		//구름이 모두 사라진다.
		//ResetCloud();

		//3. 2에서 물이 증가한 칸(r, c)에 물복사버그 마법을 시전한다.
		MagicBug();

		//4. 바구니에 저장된 물의 양이 2 이상인 모든 칸에 구름이 생기고, 물의 양이 2 줄어든다.
		ResetVec(tmp_cloud_pos);
		MakeClould();

		ResetVec(tmp_cloud_pos);
		ResetVec(tmp_arr);
		int a = 0;
	}

	int answer = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			answer += base_arr[i][j];
		}
	}
	std::cout << answer;

	return 0;
}