#include <string>
#include <vector>

using namespace std;

// ABCDEF 처리
char ToStringFunc(int n)
{
    if (n < 10)
    {
        return ('0' + n);
    }
    else
    {
        return ('A' + (n % 10));
    }
}

// t진수로 변경
std::string ChangedFunc(int n, int t)
{
    std::string ans = "";
    while (true)
    {
        ans = ToStringFunc(n % t) + ans;
        n = n / t;
        if (n <= 0)
        {
            break;
        }
    }
    return ans;
}

string solution(int n, int t, int m, int p) {
    string answer = "";
    std::vector<char> changedvec;

    int curnum = 0;

    while (true)
    {
        std::string nextnum = ChangedFunc(curnum++, n);
        for (char eachnum : nextnum)
        {
            changedvec.push_back(eachnum);
        }
        if (changedvec.size() >= (t - 1) * m + p)
        {
            break;
        }
    }

    // 내 index에 해당하는 값들 모으기
    for (int i = 0; i < t; ++i)
    {
        answer += changedvec[i * m + p - 1];
    }
    return answer;
}