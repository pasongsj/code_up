#include <string>
#include <vector>
#include <set>
#include <iostream>
#include <algorithm>

using namespace std;

std::vector<std::vector<int>> resall;
std::vector<int> comb;


std::string vectostring()
{
    std::string res = "";
    for (int a : comb)
    {
        res += to_string(a);
    }
    return res;
}

bool CheckCandidate(const vector<vector<string>>& Vec)
{
    std::hash<string> str_hash;
    int datacnt = Vec.size();
    int keycnt = Vec[0].size();
    std::set<size_t> alldata;
    for (int i = 0; i < datacnt; ++i)
    {
        std::string tmp = "";
        for (int j : comb)
        {
            tmp += Vec[i][j];
        }
        size_t hashtmp = str_hash(tmp);
        if (alldata.end() != alldata.find(hashtmp))
        {
            return false;
        }
        alldata.insert(hashtmp);
    }
    return true;
}

void getcomb(int startindex, int maxcnt, const vector<vector<string>>& Vec)
{
    if (true == CheckCandidate(Vec))
    {
        resall.push_back(comb);
        return;
    }
    if (maxcnt == comb.size())
    {
        return;
    }
    for (int i = startindex; i < maxcnt; ++i)
    {
        comb.push_back(i);
        getcomb(i + 1, maxcnt, Vec);
        comb.pop_back();
    }
}


int solution(vector<vector<string>> relation) {
    int answer = 0;
    int keycnt = relation[0].size();

    getcomb(0, keycnt, relation);

    std::sort(resall.begin(), resall.end(), [](const std::vector<int>& _a, const std::vector<int>& _b)
        {
            return _a.size() < _b.size();
        });
    std::set<int> notindex;
    for (int i = 0; i < resall.size(); ++i)
    {
        if (notindex.end() != notindex.find(i))
        {
            continue;
        }
        for (int j = i + 1; j < resall.size(); ++j)
        {
            bool is_min = false;
            for (int k : resall[i])
            {
                if (resall[j].end() == find(resall[j].begin(), resall[j].end(), k))
                {
                    is_min = true;
                    break;
                }
            }
            if (false == is_min)
            {
                notindex.insert(j);
            }
        }
    }

    answer = resall.size() - notindex.size();
    return answer;
}
