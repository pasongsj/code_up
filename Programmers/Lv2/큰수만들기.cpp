#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string number, int k) {
    string answer = "";

    int index = 1;

    while (k > 0)
    {
        if (number[index - 1] < number[index])
        {
            number.erase(index - 1, 1);
            k--;
            if (index > 1)
            {
                index--;
            }
        }
        else if (index == number.size() - 1)
        {
            number.erase(index, 1);
            k--;
            index--;
        }
        else
        {
            index++;
        }
    }
    answer = number;
    return answer;
}