#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    int i = 0;
    while(++i<=n/i){
        if(n%i==0){
            answer+=(i + n/i);
            if(i == n/i)    answer-=i;
        }
    }
    return answer;
}
