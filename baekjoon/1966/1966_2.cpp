#include <iostream>
#include <vector>
#include <queue>

int main()
{
	int T;
	std::cin >> T;
	while (T--)
	{
		int n, m; // ��������, //m��° �ε��� �� ���° ��µǴ���?
		std::cin >> n >> m;
		std::queue<std::pair<int, int>> q;
		std::priority_queue<int> importq;

		//�Է�
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
			if (importq.top() == q.front().second) // ���� ���� ���� ū ���̶��
			{
				printindex++; // �μ��Ѵ�.
				if (q.front().first == m) // ���� ���� ã�� �ε������ ���° ����Ʈ���� Ȯ���Ѵ�.
				{
					break;
				}
				importq.pop();
				q.pop();
			}
			else // ���� ����Ʈ �ؾ� �� �߿䵵�� �ƴ϶�� �ļ����� �����Ѵ�.
			{
				q.push(q.front());
				q.pop();

			}
		}
		std::cout << printindex << '\n';
	}

	return 0;

}