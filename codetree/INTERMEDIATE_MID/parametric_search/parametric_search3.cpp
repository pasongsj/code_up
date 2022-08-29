#include <iostream>
#include <algorithm>
using namespace std;

long long is_possible(long long num){
    return num - (num/3 + num/5 - num/15);
}


long long find_moo(long long num){
    long long left = 1, right = num*2, idx = num*2;

    while(left<=right){
        long long mid = (left + right)/2;
        if(num<=is_possible(mid)){
            right = mid-1;
            idx = min(idx, mid);
        }
        else    left = mid+1;
    }
    return idx;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    long long n;
    cin >> n;
    cout<<find_moo(n);
}
