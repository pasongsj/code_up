#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    std::map<std::string, int> dic;
    int index = 1;
    for (; index < 27;)
    {
        std::string curStr = "";
        curStr += ('A' + index - 1);
        dic[curStr] = index++;

    }

    int start = 0;
    for (; start < msg.size();)
    {
        int range = 1;
        int lastans = 0;
        while (true)
        {
            std::string nextstr = msg.substr(start, range);
            if (start + range > msg.size())
            {
                break;
            }
            if (dic.end() == dic.find(nextstr))
            {
                dic[nextstr] = index++;
                break;
            }
            lastans = dic[nextstr];
            range++;
        }
        answer.push_back(lastans);

        start += (range - 1);

    }

    return answer;
}