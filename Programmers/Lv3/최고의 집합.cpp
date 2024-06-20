#include <string>
#include <vector>
#include <set>

using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;

    int div_res = s / n;
    int remain_res = s % n;
    if (div_res == 0)
    {
        answer.push_back(-1);
    }
    else
    {
        for (int i = 0; i < n; ++i)
        {
            answer.push_back(div_res);
        }
        int index = answer.size() - 1;
        while (remain_res)
        {
            answer[index]++;
            remain_res--;
            index--;
        }
    }
    return answer;
}