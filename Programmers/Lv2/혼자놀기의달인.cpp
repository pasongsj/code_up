#include <string>
#include <vector>
#include <queue>


using namespace std;

int solution(vector<int> cards) {
    int answer = 0;
    std::vector<int> pluse1_cards;
    pluse1_cards.resize(cards.size() + 1);

    std::priority_queue<int> q;
    for (int i = 1; i <= cards.size(); ++i)
    {
        pluse1_cards[i] = cards[i - 1];
    }

    while (true)
    {
        int next_index = -1;
        for (int i = 1; i <= cards.size(); ++i)
        {
            if (-1 != pluse1_cards[i])
            {
                next_index = i;
                break;
            }
        }
        if (-1 == next_index)
        {
            break;
        }
        int cnt = 0;
        while (-1 != next_index)
        {
            int tmp = pluse1_cards[next_index];
            pluse1_cards[next_index] = -1;
            next_index = tmp;
            cnt++;
        }

        q.push(cnt);
    }

    if (q.size() < 2)
    {
        return 0;
    }
    answer = q.top() - 1;
    q.pop();
    answer *= (q.top() - 1);
    return answer;
}