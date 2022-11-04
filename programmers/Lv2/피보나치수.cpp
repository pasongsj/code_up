#include <string>
#include <vector>
#define MAX_N 100001
using namespace std;

int solution(int n) {
    int arr[MAX_N];
    arr[0] = 0;
    arr[1]= 1;
    
    for(int i=2;i<=n;i++){
        arr[i] = (arr[i-1]+ arr[i-2])%1234567;
    }
    return arr[n];
}
