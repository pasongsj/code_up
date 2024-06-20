#include <string>
#include <vector>
#include <iostream>
#include <set>

using namespace std;

int solution(vector<int> elements) {
    int answer = 0;
    std::set<int> ansset;
    int n = elements.size();
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            int sum = 0;
            for (int k = j; k < j + i; ++k)
            {
                sum += elements[k % n];
            }
            ansset.insert(sum);
        }
    }
    answer = ansset.size();
    return answer;
}