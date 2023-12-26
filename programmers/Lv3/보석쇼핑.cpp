#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>


using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer;
    answer.resize(2);
    answer[0] = 1, answer[1] = gems.size();
    int start = 0, end = 0;

    // ������ �ִ� ���� ������ ����
    std::unordered_map<std::string, int> kind_of_gems;
    // ������ �ִ� ���� ���� ��
    std::unordered_set<std::string> ownd_type;

    for (const std::string& gem : gems)
    {
        ownd_type.insert(gem);
    }

    int total_gems = ownd_type.size();
    int cur_len = gems.size();

    ownd_type.clear();

    for (;start < gems.size();++start)
    {
        // ��� ������ ���������� end++
        while (ownd_type.size() < total_gems && end < gems.size())
        {
            std::string cur_gem = gems[end++];
            ownd_type.insert(cur_gem);
            kind_of_gems[cur_gem]++;
        }

        // ��� ����
        if (ownd_type.size() == total_gems && end - start < cur_len)
        {
            answer[0] = start + 1;
            answer[1] = end;
            cur_len = end - start;
        }

        // start �� ����
        if (1 == kind_of_gems[gems[start]])
        {
            ownd_type.erase(gems[start]);
        }
        kind_of_gems[gems[start]]--;
    }

    return answer;
}