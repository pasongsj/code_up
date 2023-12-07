#include <iostream>
#include <vector>
#include <queue>


int main()
{
    int n = 0, answer = 0;


    std::vector<int> count; //weight
    std::vector<std::vector<int>> preworklist;  // 선행노드
    std::vector<int> dp; // 누적합
    std::vector<int> ancestor; // 진입차수 cnt

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
            q.push(i); // 진입차수가 없는 것
        }

    }

    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int i = 0; i < preworklist[cur].size(); i++) {
            int next = preworklist[cur][i];
            dp[next] = std::max(dp[next], dp[cur] + count[next]);
            ancestor[next]--;
            if (ancestor[next] == 0) // 진입차수가 0이라면
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