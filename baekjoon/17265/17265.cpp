#include <iostream>
#include <vector>


int n;

bool InRange(int x, int y)
{
	return 0 <= x && x < n && 0 <= y && y < n;
}

int GetRes(int a, int b, char oper)
{
	switch (oper)
	{
	case '+':
		return a + b;
	case '-':
		return a - b;
	case '*':
		return a * b;
	default:
		break;
	}
	return INT32_MAX;
}

int main()
{
	std::cin >> n;
	std::vector<std::vector<char>> arr_path;
	std::vector<std::vector<int>> arr_max;
	std::vector<std::vector<int>> arr_min;


	arr_path.resize(n);
	arr_max.resize(n);
	arr_min.resize(n);
	for (int i = 0; i < n; ++i)
	{
		arr_path[i].resize(n);
		arr_max[i].resize(n);
		arr_min[i].resize(n);
		for (int j = 0; j < n; ++j)
		{
			std::cin >> arr_path[i][j];
			arr_min[i][j] = INT32_MAX;
			arr_max[i][j] = INT32_MIN;
		}
	}


	arr_min[0][0] = arr_path[0][0] - '0';
	arr_max[0][0] = arr_path[0][0] - '0';
	const int dx[2] = {1,0};
	const int dy[2] = {0,1};
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if('0' <= arr_path[i][j] && arr_path[i][j]<='5')
			{
				for (int k = 0; k < 2; ++k)
				{
					int nx = i + dx[k];
					int ny = j + dy[k];
					if (true == InRange(nx, ny))
					{
						char cur_oper = arr_path[nx][ny];
						for (int l = 0; l < 2; ++l)
						{
							int bx = nx + dx[l];
							int by = ny + dy[l];
							if (true == InRange(bx, by))
							{
								int tmp_min = GetRes(arr_min[i][j], arr_path[bx][by] - '0', cur_oper);
								arr_min[bx][by] = arr_min[bx][by] > tmp_min ? tmp_min : arr_min[bx][by];

								int tmp_max = GetRes(arr_max[i][j], arr_path[bx][by] - '0', cur_oper);
								arr_max[bx][by] = arr_max[bx][by] < tmp_max ? tmp_max : arr_max[bx][by];
							}
						}
					}
				}
			}
		}
	}

	std::cout << arr_max[n - 1][n - 1] << ' ' << arr_min[n - 1][n - 1];
	return 0;
}