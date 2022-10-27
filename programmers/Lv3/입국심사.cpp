#include <vector>
#include <algorithm>

using namespace std;
 
long long solution(int n, vector<int> times) {
    long long answer = 0;
    long long left = 1;
    long long right = *max_element(times.begin(),times.end()) * (long long)(n);
    while (left <= right)
    {
        long long cnt = 0;
        long long mid = ((left + right) / 2);
        for (auto t : times)    cnt += mid/t;

        if (n <= cnt)
        {
            answer = mid;
            right = mid - 1;
        }
        else    left = mid + 1;
    }
    return answer;
}
