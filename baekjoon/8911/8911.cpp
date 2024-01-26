#include <iostream>
#include <string>
#include <vector>
// F: 한 눈금 앞으로
// B: 한 눈금 뒤로
// L : 왼쪽으로 90도 회전
// R : 오른쪽으로 90도 회전


				// 북 동 남 서
const int dx[4] = { -1,0,1,0 };
const int dy[4] = { 0,1,0,-1 };


int GetRect()
{
	int min_x = 0, max_x = 0;
	int min_y = 0, max_y = 0;
	std::string inputstr;
	std::cin >> inputstr;

	int cx = 0, cy = 0;
	int dir = 0;

	for (char curinput : inputstr)
	{
		switch (curinput)
		{
		case 'F':
		{
			cx += dx[dir];
			cy += dy[dir];
			break;
		}
		case 'B':
		{
			cx += dx[(dir + 2) % 4];
			cy += dy[(dir + 2) % 4];
			break;
		}
		case 'L':
		{
			dir = (dir + 3) % 4;
			break;
		}
		case 'R':
		{
			dir = (dir + 1) % 4;
			break;
		}
		default:
			break;
		}
		max_x = max_x > cx ? max_x : cx;
		min_x = min_x < cx ? min_x : cx;

		max_y = max_y > cy ? max_y : cy;
		min_y = min_y < cy ? min_y : cy;
	}

	return (max_x - min_x) * (max_y - min_y);

}


int main()
{
	int n;
	std::cin >> n;
	std::vector<int> answer;
	while (n--)
	{
		answer.push_back(GetRect());
	}

	for (int ans : answer)
	{
		std::cout << ans << '\n';
	}
	return 0;
}