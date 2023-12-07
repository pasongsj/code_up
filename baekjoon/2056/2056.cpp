#include <iostream>
#include <vector>
#include <queue>


int main()
{
    int n = 0, answer = 0;


    std::vector<int> count; //weight
    std::vector<std::vector<int>> preworklist;  // ������
    std::vector<int> dp; // ������
    std::vector<int> ancestor; // �������� cnt

    std::cin >> n;
    count.resize(n + 1);
    dp.resize(n + 1);
    ancestor.resize(n + 1);
    preworklist.resize(n + 1);

    std::queue<int> q;
    for (int i = 1; i <= n; i++) {
        int x;
        std::cin >> count[i] >> x;
        dp[i] = count[i];
        ancestor[i] = x;

		for (int j = 0; j < x; j++) {
			int pre;
			std::cin >> pre;
			preworklist[pre].push_back(i);
		}
        if (0 == x)
        {
            q.push(i); // ���������� ���� ��
        }

    }

    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int i = 0; i < preworklist[cur].size(); i++) {
            int next = preworklist[cur][i];
            dp[next] = std::max(dp[next], dp[cur] + count[next]);
            ancestor[next]--;
            if (ancestor[next] == 0) // ���������� 0�̶��
            {
                q.push(next);
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        answer = std::max(answer, dp[i]);
    }
    std::cout << answer;
}