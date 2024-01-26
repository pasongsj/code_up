#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

std::vector<std::vector<char>> field;
std::vector<std::vector<int>> is_visited;

void Swap(std::pair<int, int> a, std::pair<int, int> b)
 {
	char tmp = field[a.first][a.second];
	field[a.first][a.second] = field[b.first][b.second];
	field[b.first][b.second] = tmp;
}

void ResetVisit()
{
	for (int i = 0; i < 12; ++i)
	{
		for (int j = 0; j < 6; ++j)
		{
			is_visited[i][j] = 0;
		}
	}
}

void Drop()
{
	for (int j = 0; j < 6; ++j)
	{
		for (int i = 11; i > 0; --i)
		{
			if(field[i][j] == '.')
			{
				int deep = i-1;
				while (deep > 0)
				{
					if (field[deep][j] != '.')
					{
						break;
					}
					deep--;
				}
				Swap(std::make_pair(i, j), std::make_pair(deep, j));
			}
		}
	}
}

bool InRange(int x, int y)
{
	return 0 <= x && x < 12 && 0 <= y && y < 6;
}

bool DeletCheck(std::pair<int, int> start)
{
	int cx = start.first, cy = start.second;
	char alpha = field[cx][cy];

	const int dx[4] = { 0,0,1,-1 };
	const int dy[4] = { 1,-1,0,0 };

	std::vector<std::pair<int, int>> list;
	std::queue<std::pair<int, int>> q;

	is_visited[cx][cy] = true;
	q.push(std::make_pair(cx, cy));
	list.push_back(std::make_pair(cx, cy));

	while (!q.empty())
	{
		std::tie(cx, cy) = q.front();
		q.pop();
		for (int i = 0; i < 4; ++i)
		{
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (true == InRange(nx, ny) && false == is_visited[nx][ny] && alpha == field[nx][ny])
			{
				is_visited[nx][ny] = 1;
				q.push(std::make_pair(nx, ny));
				list.push_back(std::make_pair(nx, ny));
			}
		}
	}
	if (list.size() >= 4)
	{
		for (const std::pair<int, int>& point : list)
		{
			field[point.first][point.second] = '.';
		}
		return true;
	}
	return false;
}

bool BspCheck()
{
	ResetVisit();
	bool isDelete = false;
	for (int i = 0; i < 12; ++i)
	{
		for (int j = 0; j < 6; ++j)
		{
			if ('.' == field[i][j] || 1 == is_visited[i][j])
			{
				continue;
			}
			if (true == DeletCheck(std::make_pair(i, j)))
			{
				isDelete = true;
			}
		}
	}
	Drop();
	return isDelete;
}


int main()
{
	field.resize(12);
	is_visited.resize(12);
	for (int i = 0; i < 12; ++i)
	{
		field[i].resize(6);
		is_visited[i].resize(6);
		for (int j = 0; j < 6; ++j)
		{
			std::cin >> field[i][j];
		}
	}
	int answer = 0;
	while (true)
	{
		if (true == BspCheck())
		{
			answer++;
		}
		else
		{
			break;
		}
	}
	std::cout << answer;
	return 0;
}