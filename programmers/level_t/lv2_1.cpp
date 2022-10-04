#include <string>
#include <vector>

using namespace std;
#define MAX_N 60000

int arr[MAX_N+1];
int solution(int n) {
    int answer = 0;
    arr[1] = 1;
    arr[2] = 2;
    for(int i=3;i<=n;i++){
        arr[i] = (arr[i-1] + arr[i-2])%1000000007;
    }
    answer = arr[n];
    return answer;
}
