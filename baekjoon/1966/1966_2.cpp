#include <iostream>
#include <vector>
#include <queue>

int main()
{
	int T;
	std::cin >> T;
	while (T--)
	{
		int n, m; // 문서개수, //m번째 인덱스 가 몇번째 출력되는지?
		std::cin >> n >> m;
		std::queue<std::pair<int, int>> q;
		std::priority_queue<int> importq;

		//입력
		for (int i = 0; i < n; ++i)
		{
			int tmp;
			std::cin >> tmp;
			q.push(std::make_pair(i, tmp));
			importq.push(tmp);
			//std::cin >> arr[i];
		}
		
		int printindex = 0;
		while (true)
		{
			if (q.empty())
			{
				break;
			}
			if (importq.top() == q.front().second) // 현재 값이 가장 큰 값이라면
			{
				printindex++; // 인쇄한다.
				if (q.front().first == m) // 만약 내가 찾던 인덱스라면 몇번째 프린트인지 확인한다.
				{
					break;
				}
				importq.pop();
				q.pop();
			}
			else // 현재 프린트 해야 할 중요도가 아니라면 후순위로 변경한다.
			{
				q.push(q.front());
				q.pop();

			}
		}
		std::cout << printindex << '\n';
	}

	return 0;

}