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
	// �Է¹���
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
		if (0 == arr[r][c]) // ���� ĭ�� ���� û�ҵ��� ���� ���, ���� ĭ�� û���Ѵ�.
		{
			ans++;
			arr[r][c] = 2;
		}

		bool canclean = false;
		int tmpdir = cur_dir;
		for (int i = 0;i < 4;++i)
		{
			tmpdir = (tmpdir + 3) % 4; // �ݽð� �������� ȸ��
			int nx = r + dirx[tmpdir];
			int ny = c + diry[tmpdir];
			if (true == in_range(nx, ny, n, m) && 0 == arr[nx][ny]) // û�ҵ��� ���� �� ĭ�� �ִ� ���
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
		else // û�ҵ��� ���� �� ĭ�� ���� ���
		{
			int nx = r - dirx[cur_dir];
			int ny = c - diry[cur_dir];
			if (true == in_range(nx, ny, n, m) && 1 != arr[nx][ny]) // ������ �� �ִٸ� 
			{
				r = nx;
				c = ny;
				continue;
			}
			break; // ������ �� ���ٸ� �۵��� �����.
		}
	}
	std::cout << ans;
	return 0;
}


