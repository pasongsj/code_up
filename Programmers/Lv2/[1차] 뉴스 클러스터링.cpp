#include <string>
#include <set>
#include <algorithm>

using namespace std;


bool ToLower(std::string& _str)
{
    for (int i = 0; i < _str.size(); ++i)
    {
        if (65 <= _str[i] && _str[i] <= 90)
        {
            _str[i] += 32;
        }
        else if (97 <= _str[i] && _str[i] <= 122)
        {
            continue;
        }
        else
        {
            return false;
        }
    }
    return true;
}

int solution(string str1, string str2) {
    int answer = 65536;
    std::multiset<std::string> m_str1;
    std::multiset<std::string> m_str2;

    std::set<std::string> res_intersection;
    for (int i = 0; i < str1.size() - 1; ++i)
    {
        std::string curstr = (str1.substr(i, 2));
        if (false == ToLower(curstr))
        {
            continue;
        }
        m_str1.insert(curstr);
    }
    for (int i = 0; i < str2.size() - 1; ++i)
    {
        std::string curstr = (str2.substr(i, 2));
        if (false == ToLower(curstr))
        {
            continue;
        }
        m_str2.insert(curstr);
    }
    int union_cnt = (m_str1.size() + m_str2.size());
    int intersection_cnt = 0;
    for (const std::string num : m_str1)
    {
        auto it = m_str2.find(num);
        if (m_str2.end() != it)
        {
            intersection_cnt++;
            m_str2.erase(it);
        }
    }
    union_cnt -= intersection_cnt;

    if (0 != union_cnt)
    {
        answer = 65536 * intersection_cnt / union_cnt;
    }

    return answer;
}

