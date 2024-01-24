#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

int n, m;
std::vector<std::vector<int>> arr_paper;
std::vector<std::vector<int>> is_visited;

int cnt;
int m_drawing;


bool InRange(int x, int y)
{
	return 0 <= x && x < n && 0 <= y && y < m;
}

void Initialize()
{
	arr_paper.resize(n);
	is_visited.resize(n);


	for (int i = 0; i < n; ++i)
	{
		arr_paper[i].resize(m);
		is_visited[i].resize(m);
		for (int j = 0; j < m; ++j)
		{
			std::cin >> arr_paper[i][j];
		}
	}
	cnt = 0;
	m_drawing = 0;
}

void GetMaXSizeOfDrawing(int i, int j)
{
	// bsp 
	const int dx[4] = { 1,-1,0,0 };
	const int dy[4] = { 0,0,1,-1 };

	std::queue<std::pair<int, int>> bsp_q;

	bsp_q.push(std::make_pair(i, j));
	is_visited[i][j] = 1;
	cnt++;
	int cur_size = 0;
	while (!bsp_q.empty())
	{
		int cx, cy;
		std::tie(cx, cy) = bsp_q.front();
		bsp_q.pop();
		cur_size++;
		for (int k = 0; k < 4; ++k)
		{
			int nx = cx + dx[k];
			int ny = cy + dy[k];
			if (true == InRange(nx, ny) && 1 == arr_paper[nx][ny] && 0 == is_visited[nx][ny])
			{
				bsp_q.push(std::make_pair(nx, ny));
				is_visited[nx][ny] = 1;
			}
		}
	}
	m_drawing = m_drawing > cur_size ? m_drawing : cur_size;
}

void FindNewDrawing()
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (1 == arr_paper[i][j] && 0 == is_visited[i][j])
			{
				// 현재 그림에 해당하는 max사이즈 찾기
				GetMaXSizeOfDrawing(i, j);
			}
		}
	}
}

int main()
{

	std::cin >> n >> m;

	//입력 받기
	Initialize();

	// 그림 찾기
	FindNewDrawing();

	std::cout << cnt << '\n' << m_drawing;
	
	return 0;
}