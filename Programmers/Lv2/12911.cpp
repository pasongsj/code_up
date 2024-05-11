#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(int n) {
    int answer = 0;
    // to bin
    list<int> bin;
    while (n > 0)
    {
        bin.push_front(n % 2);
        n /= 2;
    }
    bin.push_front(0);
    next_permutation(bin.begin(), bin.end());
    if (0 == *bin.begin())
    {
        bin.pop_front();
    }
    auto it = bin.end();
    it--;
    int twonum = 1;
    while (1)
    {
        answer += *it * twonum;
        if (it == bin.begin())
        {
            break;
        }
        twonum *= 2;
        it--;
    }
    return answer;
}