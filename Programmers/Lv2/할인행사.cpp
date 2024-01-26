#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    std::unordered_map<std::string, int> wanted_count;

    //���ϴ� ��ǰ, ���� �� ���� unordered_map�� ����
    for (int i = 0; i < want.size(); ++i)
    {
        wanted_count[want[i]] = number[i];
    }


    // i ~ i+10���� 10�ϰ� ���� ����Ʈ�� ���� ������ ��츦 üũ��
    int last_index = 0;
    for (int i = 0; i < discount.size(); ++i)
    {
        while (last_index < i + 10 && last_index < discount.size())
        {
            wanted_count[discount[last_index++]]--;
        }

        //���ϴ� ���� �� �����ߴ��� Ȯ����
        bool can_buy = true;
        for (const std::pair<std::string, int>& wanted_remain : wanted_count)
        {
            if (wanted_remain.second > 0)
            {
                can_buy = false;
                break;
            }
        }
        if (true == can_buy)
        {
            answer++;
        }


        wanted_count[discount[i]]++;
    }
    return answer;
}

// �ٳ��� 3��, ��� 2��, �� 2��, ������� 2��, ���� 1
// ġŲ, ���, ���, �ٳ���, ��, ���, �������, �ٳ���, �������, ��, ����, �ٳ���, ���, �ٳ���