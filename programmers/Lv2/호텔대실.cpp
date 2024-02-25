#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int GetTime(const std::string& _S)
{
    int ans = 0;
    ans += ((_S[0] - '0') * 10 + (_S[1] - '0')) * 60;
    ans += (_S[3] - '0') * 10 + (_S[4] - '0');
    return ans;
}

bool cmp(pair<int, int> a, pair<int, int> b)
{
    if (a.first == b.first)
    {
        return a.second < b.second;
    }
    return a.first < b.first;
}

int solution(vector<vector<string>> book_time) {
    int answer = 0;

    vector<pair<int, int>> Schedule;

    for (int i = 0;i < book_time.size();++i)
    {
        Schedule.push_back(make_pair(GetTime(book_time[i][0]), +1));
        Schedule.push_back(make_pair(GetTime(book_time[i][1]) + 10, -1));
    }

    std::sort(Schedule.begin(), Schedule.end(), cmp);

    int cur = 0;
    for (pair<int, int> book : Schedule)
    {
        cur += book.second;
        answer = answer < cur ? cur : answer;
    }
    return answer;

}