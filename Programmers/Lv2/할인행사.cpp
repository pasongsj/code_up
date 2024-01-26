#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    std::unordered_map<std::string, int> wanted_count;

    //원하는 제품, 개수 를 담은 unordered_map을 만듦
    for (int i = 0; i < want.size(); ++i)
    {
        wanted_count[want[i]] = number[i];
    }


    // i ~ i+10까지 10일간 할인 리스트를 통해 구매한 경우를 체크함
    int last_index = 0;
    for (int i = 0; i < discount.size(); ++i)
    {
        while (last_index < i + 10 && last_index < discount.size())
        {
            wanted_count[discount[last_index++]]--;
        }

        //원하는 것을 다 구매했는지 확인함
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

// 바나나 3개, 사과 2개, 쌀 2개, 돼지고기 2개, 냄비 1
// 치킨, 사과, 사과, 바나나, 쌀, 사과, 돼지고기, 바나나, 돼지고기, 쌀, 냄비, 바나나, 사과, 바나나