#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

long long int m, a, b;


int Find_count(long long num){
    long long left = 1, right = m;
    int cnt = 0;
    while(left<=right){
        long long mid = (left+right)/2;
        cnt ++;
        if(mid == num)  return cnt;
        else if(mid<num){
            left = mid + 1;
        }
        else    right = mid -1;
    }
    return cnt;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> m >> a >> b;
    int min_g = INT_MAX, max_g = INT_MIN;
    for(long long i=a;i<=b;i++){
        int count = Find_count(i);
        min_g = min(min_g,count);
        max_g = max(max_g,count);
    }
    cout << min_g<<' '<<max_g;
    return 0;
}
