#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

// 타야하는 버스 9:00 + (n-1) * t 시간에 출발하는 버스를 타야해
// 1. 마지막 버스의 빈 자리가 있다면 - 버스 출발시간이 result가 돼
// 2. 마지막 버스가 꽉찬다면 - 마지막에 타는 사람보다 1분 빠르게 와야해

int TimeToMinute(const std::string& _str)
{
    int h = (_str[0] - '0') * 10 + (_str[1] - '0');
    int m = (_str[3] - '0') * 10 + (_str[4] - '0');
    return h * 60 + m;
}

std::string IntToTime(int num)
{
    int h = num / 60;
    int m = num % 60;
    std::string ans = std::to_string(h / 10) + std::to_string(h % 10) + ':'
        + std::to_string(m / 10) + std::to_string(m % 10);
    return ans;
}

string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "";
    std::vector<int> table_int;

    int lastbus = 540 + (n - 1) * t;

    for (const std::string& table : timetable)
    {
        table_int.push_back(TimeToMinute(table));
    }
    std::sort(table_int.begin(), table_int.end());

    int curbus_time = 540;
    int left = 0, right = 0, mid = 0, last_right = 0;

    for (int i = 0; i < n; ++i)
    {
        curbus_time += t;
        right = left + m - 1;

        if (i == n - 1)
        {
            last_right = right;
        }
        while (left <= right)
        {
            mid = (left + right) / 2;
            if (table_int[mid] < curbus_time)
            {
                left = mid + 1;
            }
            else if (table_int[mid] >= curbus_time)
            {
                right = mid - 1;
            }
        }
    }
    mid = (left + right) / 2;
    if (lastbus == table_int[mid])
    {
        return IntToTime(table_int[mid] - 1);
    }

    if (last_right != mid || mid >= table_int.size() || table_int[mid] > lastbus)
    {
        return IntToTime(lastbus);
    }
    return IntToTime(table_int[mid] - 1);
}

