#include <iostream>
#include <vector>
#include <tuple>
int r, c, m;

std::vector<std::vector<int>> tank;
std::vector<std::vector<int>> aftertank;

std::vector<class Shark> sharks;

class Shark
{
public:
	int x = 0;
	int y = 0;
	int speed = 0;
	int dir = 0;
	int size = 0;
	bool is_dead = false;
};


bool in_range(int _x, int _y)
{
	return 0 < _x && _x <= r && 0 < _y && _y <= c;
}

void Reset_aftertank()
{
	for (int i = 0; i <= r; ++i)
	{
		for (int j = 0; j <= c; ++j)
		{
			aftertank[i][j] = 0;
		}
	}
}

void CpyTank()
{
	for (int i = 0; i <= r; ++i)
	{
		for (int j = 0; j <= c; ++j)
		{
			tank[i][j] = aftertank[i][j];
		}
	}
}


const int nx[5] = { 0, -1, 1, 0, 0 };
const int ny[5] = { 0, 0, 0, 1, -1 };

void cal_shark(int index)
{
	//s�� �ӷ�, d�� �̵� ����, z�� ũ���̴�. d�� 1�� ���� ��, 2�� ���� �Ʒ�, 3�� ���� ������, 4�� ���� ����
	int speed = sharks[index].speed;
	int cx = sharks[index].x;
	int cy = sharks[index].y;
	int dir = sharks[index].dir;
	
	if (dir == 1 || dir == 2)
	{
		speed %= ((r - 1) * 2);
	}
	else if (dir == 3 || dir == 4)
	{
		speed %= ((c - 1) * 2);
	}
	while(speed--)
	{
		if (false == in_range(cx + nx[dir], cy + ny[dir]))
		{
			switch (dir)
			{
			case 1:
				dir = 2;
				break;
			case 2:
				dir = 1;
				break;
			case 3:
				dir = 4;
				break;
			case 4:
				dir = 3;
				break;
			}
		}
		cx += nx[dir];
		cy += ny[dir];
	}

	sharks[index].x = cx;
	sharks[index].y = cy;
	sharks[index].dir = dir;

	if (0 != aftertank[cx][cy])
	{
		if (sharks[aftertank[cx][cy]].size > sharks[index].size)
		{
			// ���� index�� ����
			sharks[index].is_dead = true;
		}
		else
		{
			// ���� �ִ��� ����
			sharks[aftertank[cx][cy]].is_dead = true;
			aftertank[cx][cy] = index;
		}
	}
	else
	{
		aftertank[cx][cy] = index;
	}
}

int main()
{
	int answer = 0;
	std::cin >> r >> c >> m;
	
	aftertank.resize(r + 1);
	tank.resize(r + 1);
	for (int i = 0; i <= r; ++i)
	{
		aftertank[i].resize(c + 1);
		tank[i].resize(c + 1);
	}

	sharks.resize(m + 1);
	for (int i = 1; i <= m; ++i)
	{
		std::cin >> sharks[i].x >> sharks[i].y >> sharks[i].speed >> sharks[i].dir >> sharks[i].size;
		tank[sharks[i].x][sharks[i].y] = i;
	}


	for (int i = 1; i <= c; ++i)
	{
		Reset_aftertank();
		for (int j = 1; j <= r; ++j)
		{
			if (0 != tank[j][i] && false == sharks[tank[j][i]].is_dead)
			{
				// ���ÿ��� �ִ� ���� �ִ� ��� �߿��� ���� ���� ����� �� ��´�. �� ������ �����ǿ��� ���� �� �������.
				int shark_index = tank[j][i];
				answer += sharks[shark_index].size;
				sharks[shark_index].is_dead = true;
				tank[j][i] = 0;
				break;
			}
		}
		// �� �̵��Ѵ�.
		for (int k = 1; k <= m; ++k)
		{
			if (true == sharks[k].is_dead) // �̹� ���� ����.
			{
				continue;
			}
			cal_shark(k);
		}
		CpyTank();
	}
	std::cout << answer;
	return 0;
}