// 15685.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <tuple>
#include <set>

const int dx[4] = { 1, 0, -1, 0 };
const int dy[4] = { 0, -1, 0, 1 };


std::pair<int, int> RotatePoint(std::pair<int, int> pivot, std::pair<int, int> point)
{
	std::pair<int, int> res = point;
	point.first -= pivot.first;
	point.second -= pivot.second;


	int tmp = point.first;
	point.first = -point.second;
	point.second = tmp;

	point.first+= pivot.first;
	point.second += pivot.second;

	return point;
}


int main()
{
	int n;
	//std::vector<std::pair<int, int>> respoints;
	std::set<std::pair<int, int>> respoints;
	std::cin >> n;
	for (int i = 0; i < n; ++i)
	{
		std::vector<std::pair<int, int>> curpoints;
		int x, y, d, g;
		std::cin >> x >> y >> d >> g;
		curpoints.push_back(std::make_pair(x, y));
		int pivotx = x + dx[d];
		int pivoty = y + dy[d];
		curpoints.push_back(std::make_pair(pivotx, pivoty));

		while (g--)
		{
			pivotx = curpoints.back().first;
			pivoty = curpoints.back().second;
			for (int y = curpoints.size() - 2; y >= 0; y--)
			{
				std::pair<int, int> nextpoint;
				int nx, ny;
				nextpoint = RotatePoint(std::make_pair(pivotx, pivoty), curpoints[y]);
				curpoints.push_back(nextpoint);
			}
		}
		for (const std::pair<int, int>& p : curpoints)
		{
			respoints.insert(p);
		}
	}

	int answer = 0;

	for (const std::pair<int, int>& p : respoints)
	{
		std::pair<int, int> rpoint = p;
		rpoint.first++;
		std::pair<int, int> dpoint = p;
		dpoint.second++;
		std::pair<int, int> rdpoint= p;
		rdpoint.first++;
		rdpoint.second++;
		if (
			respoints.end() != respoints.find(rpoint) &&
			respoints.end() != respoints.find(dpoint) &&
			respoints.end() != respoints.find(rdpoint)
			)
		{
			answer++;
		}

	}

	std::cout << answer;

	return 0;
}
