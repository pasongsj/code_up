#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    sort(people.begin(), people.end());
    int begin = 0, end = people.size() - 1;
    while (begin <= end)
    {
        if (people[begin] + people[end] <= limit)
        {
            begin++;
        }
        end--;
        answer++;
    }
    return answer;
}