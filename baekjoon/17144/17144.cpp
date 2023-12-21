#include <iostream>
#include <vector>

int r, c, t;
const int n_x[4] = { 0,0,1,-1 };
const int n_y[4] = { 1,-1,0,0 };

const int r_clock_x[4] = { 0,-1,0,1 };
const int r_clock_y[4] = { 1,0,-1,0 };

const int clock_x[4] = { 0,1,0,-1 };
const int clock_y[4] = { 1,0,-1,0 };

int upper_x, upper_y;
int bot_x, bot_y;

bool in_range(int x, int y)
{
	return 0 <= x && x < r && 0 <= y && y < c;
}

void Wind(const std::vector<std::vector<int>>& cur_room, std::vector<std::vector<int>>& next_room)
{
	//cpy_room(next_room, cur_room);
	//upper
	{
		int curdir = 0;
		int cx = upper_x+ r_clock_x[curdir];
		int cy = upper_y+ r_clock_y[curdir];
		next_room[cx][cy] = 0;
		int nx = cx+ r_clock_x[curdir];
		int ny = cy+ r_clock_y[curdir];
		while (true)
		{
			if (nx == upper_x && ny == upper_y)
			{
				break;
			}
			next_room[nx][ny] = cur_room[cx][cy];
			cx = nx;
			cy = ny;


			nx = cx + r_clock_x[curdir];
			ny = cy + r_clock_y[curdir];

			if (false == in_range(nx, ny))
			{
				curdir++;
				nx = cx +r_clock_x[curdir];
				ny = cy +r_clock_y[curdir];
			}
		}
		next_room[upper_x][upper_y] = 0;
	}
	//bot
	{
		int curdir = 0;
		int cx = bot_x + clock_x[curdir];
		int cy = bot_y + clock_y[curdir];
		next_room[cx][cy] = 0;

		int nx = cx + clock_x[curdir];
		int ny = cy + clock_y[curdir];
		while (true)
		{
			if (nx == bot_x && ny == bot_y)
			{
				break;
			}
			next_room[nx][ny] = cur_room[cx][cy];
			cx = nx;
			cy = ny;


			nx = cx + clock_x[curdir];
			ny = cy + clock_y[curdir];

			if (false == in_range(nx, ny))
			{
				curdir++;
				nx = cx + clock_x[curdir];
				ny = cy + clock_y[curdir];
			}
		}
		next_room[bot_x][bot_y] = 0;

	}
}

void reset(std::vector<std::vector<int>>& arr)
{
	for (int i = 0;i < r;++i)
	{
		for (int j = 0;j < c;++j)
		{
			arr[i][j] = 0;
		}
	}
}



void GetNextVec(const std::vector<std::vector<int>>& cur_room, std::vector<std::vector<int>>& next_room)
{
	
	for (int i = 0;i < r;++i)
	{
		for (int j = 0;j < c;++j)
		{
			if (cur_room[i][j] > 0)
			{
				int dust = cur_room[i][j];
				int spread_dust = dust / 5;
				for (int k = 0;k < 4;++k)
				{
					int ni = i + n_x[k];
					int nj = j + n_y[k];
					if (true == in_range(ni, nj) && -1 != cur_room[ni][nj])
					{
						next_room[ni][nj] += spread_dust;
						dust -= spread_dust;
					}
				}
				next_room[i][j] += dust;
			}
		}
	}
}

void cpy_room(std::vector<std::vector<int>>& cur_room, const std::vector<std::vector<int>>& next_room)
{
	for (int i = 0;i < r; ++i)
	{
		for (int j = 0;j < c;++j)
		{
			if (cur_room[i][j] == -1)
			{
				continue;
			}
			cur_room[i][j] = next_room[i][j];
		}
	}
}

void Print(const std::vector<std::vector<int>>& room)
{
	std::cout << '\n';

	for (int i = 0;i < r; ++i)
	{
		for (int j = 0;j < c;++j)
		{
			std::cout<< room[i][j]<<' ';
		}
		std::cout << '\n';
	}
}

int getalldust(const std::vector<std::vector<int>>& room)
{
	int ans = 0;
	for (int i = 0;i < r; ++i)
	{
		for (int j = 0;j < c;++j)
		{
			ans+=room[i][j];
		}
	}
	return ans;
}


int main()
{

	std::cin >> r >> c >> t;
	std::vector<std::vector<int>> room(r, std::vector<int>(c, 0));
	std::vector<std::vector<int>> nextroom(r, std::vector<int>(c, 0));

	bool is_up = true;
	for (int i = 0;i < r; ++i)
	{
		for (int j = 0;j < c;++j)
		{
			std::cin >> room[i][j];
			if (room[i][j] == -1)
			{
				if (true == is_up)
				{
					upper_x = i;
					upper_y = j;
					is_up = false;
				}
				else
				{
					bot_x = i;
					bot_y = j;
				}
			}
		}
	}
	while (t--)
	{
		reset(nextroom);
		GetNextVec(room, nextroom);
		cpy_room(room, nextroom);
		Wind(room, nextroom);
		cpy_room(room, nextroom);
	}
	int answer = getalldust(room)+2;
	std::cout << answer;


	return 0;
}