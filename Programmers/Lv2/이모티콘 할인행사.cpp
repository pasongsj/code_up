#include <string>
#include <vector>

using namespace std;
std::vector<int> answer;

void Cal(const std::vector<int>& comb, const std::vector<std::vector<int>>& user, const std::vector<int>& emot)
{
    int cnt = 0;
    int allcnt = 0;
    for (const std::vector<int>& euser : user)
    {
        int prices = 0;
        for (int i = 0; i < emot.size(); ++i)
        {
            if (comb[i] < euser[0])
            {
                continue;
            }
            prices += (emot[i] * (100 - comb[i])) / 100;
        }
        if (prices >= euser[1])
        {
            cnt++;
        }
        else
        {
            allcnt += prices;
        }
    }
    if (answer[0] < cnt || (answer[0] == cnt && answer[1] < allcnt))
    {
        answer[0] = cnt;
        answer[1] = allcnt;
    }
    return;
}


void DFS(std::vector<int>& combi, const std::vector<std::vector<int>>& user, const std::vector<int>& emot)
{
    if (combi.size() == emot.size())
    {
        Cal(combi, user, emot);
        return;
    }
    for (int i = 10; i <= 40; i += 10)
    {
        combi.push_back(i);
        DFS(combi, user, emot);
        combi.pop_back();
    }
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    std::vector<int> comb;
    answer.resize(2);
    DFS(comb, users, emoticons);
    return answer;
}
