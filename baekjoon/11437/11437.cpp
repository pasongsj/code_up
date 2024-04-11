// 11437.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <queue>
int n;
std::vector<std::vector<int>> graph;
std::vector<int> grade;
std::vector<int> Level;

void DecideLevel()
{
    // init
    std::queue<int> q;
    for (int i = 1; i <= n; ++i)
    {
        if (grade[i] == 1 && i != 1)
        {
            q.push(i);
            Level[i] = 1;
        }
    }
    grade[1]++;
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        for (int i = 0; i < graph[cur].size(); ++i)
        {
            int next = graph[cur][i];
            grade[next]--;
            bool isinit = false;
            if (grade[next] == 1)
            {
                q.push(next);
				Level[next] = std::max(Level[cur], Level[next]) + 1;
            }
			else if (grade[next] > 1 && Level[next] == 0)
            {
                Level[next] = Level[cur] + 1;
            }
        }
    }
}

int GetParent(int a, int b)
{
    std::vector<bool> isvisited(n + 1, false);
    std::queue<int> q;
    q.push(a);
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
		isvisited[cur] = true;
        for (int i = 0; i < graph[cur].size(); ++i)
        {
            int next = graph[cur][i];
            if (Level[next] > Level[cur])
            {
                q.push(next);
            }
        }
    }


    q.push(b);
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        if (true == isvisited[cur])
        {
            return cur;
        }
        isvisited[cur] = true;
        for (int i = 0; i < graph[cur].size(); ++i)
        {
            int next = graph[cur][i];
            if (Level[next] > Level[cur])
            {
                q.push(next);
            }
        }
    }
    return 1;
}

int main()
{
    // input
    std::cin >> n;
    graph.resize(n + 1);
    grade.resize(n + 1);
    Level.resize(n + 1);
    for (int i = 1; i < n; ++i)
    {
        int a, b;
        std::cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
        grade[a]++;
        grade[b]++;
    }

    DecideLevel();

    int m;
    std::cin >> m;
    std::vector<int> answer;
    for (int i = 0; i < m; ++i)
    {
        int a, b;
        std::cin >> a >> b;
        answer.push_back(GetParent(a, b));
    }
    for (int ans : answer)
    {
        std::cout << ans << '\n';
    }
    return 0;
}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
