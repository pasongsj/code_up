//1. ��� ������ di �������� siĭ �̵��Ѵ�.
//2. �� �������� �� ���� ������ �ִ� ĭ�� �ٱ��Ͽ� ����� ���� ���� 1 �����Ѵ�.
//������ ��� �������.
//3. 2���� ���� ������ ĭ(r, c)�� ��������� ������ �����Ѵ�.��������� ������ ����ϸ�, �밢�� �������� �Ÿ��� 1�� ĭ�� ���� �ִ� �ٱ����� ����ŭ(r, c)�� �ִ� �ٱ����� ���� ���� �����Ѵ�.
//�̶��� �̵��� �ٸ��� ��踦 �Ѿ�� ĭ�� �밢�� �������� �Ÿ��� 1�� ĭ�� �ƴϴ�.
//���� ���, (N, 2)���� ������ �밢�� ĭ��(N - 1, 1), (N - 1, 3)�̰�, (N, N)���� ������ �밢�� ĭ��(N - 1, N - 1)���̴�.
//4. �ٱ��Ͽ� ����� ���� ���� 2 �̻��� ��� ĭ�� ������ �����, ���� ���� 2 �پ���.�̶� ������ ����� ĭ�� 3���� ������ ����� ĭ�� �ƴϾ�� �Ѵ�.

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

// (N, 1), (N, 2), (N-1, 1), (N-1, 2)�� �񱸸��� �����
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

		//1. ��� ������ di �������� siĭ �̵��Ѵ�.
		MoveCloud(d, s);

		// 2. �� �������� �� ���� ������ �ִ� ĭ�� �ٱ��Ͽ� ����� ���� ���� 1 �����Ѵ�.

		AddCouldToBase();

		//������ ��� �������.
		//ResetCloud();

		//3. 2���� ���� ������ ĭ(r, c)�� ��������� ������ �����Ѵ�.
		MagicBug();

		//4. �ٱ��Ͽ� ����� ���� ���� 2 �̻��� ��� ĭ�� ������ �����, ���� ���� 2 �پ���.
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