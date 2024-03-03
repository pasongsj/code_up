#include <iostream>
#include <vector>

class Point
{
public:
	long long x;
	long long y;
};

int main()
{
	int n;
	std::cin >> n;


	std::vector<Point> points;
	for (int i = 0; i < n; ++i)
	{
		long long x, y;
		std::cin >> x >> y;
		points.push_back({ x,y });
	}
	points.push_back(points[0]);

	double answer = 0;

	for (int i = 0; i < n; i++)
	{
		answer += points[i].x * points[i + 1].y;
		answer -= points[i].y * points[i + 1].x;
	}
	if (answer < 0)
	{
		answer *= -1;
	}
	answer /= 2;
	std::cout << std::fixed;
	std::cout.precision(1);

	std::cout << answer;
	return 0;

}