#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long GetRes(long long d, long long x, long long k)
{
    return static_cast<long long>(sqrt(d * d - x * x * k * k)) / k;
}

long long solution(int k, int d) {
    long long answer = 0;
    for (long long x = 0; x <= d / k; ++x)
    {
        answer += GetRes(d, x, k) + 1;
    }
    return answer;
}