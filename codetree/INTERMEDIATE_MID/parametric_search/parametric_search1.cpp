#include <iostream>
using namespace std;

long long int sum(long long int n){
    return n*(n+1)/2;
}
int Find(int target){
    int left = 1, right = target,ans = -1;
    while(left<=right){
        int mid = (left + right)/2;
        if(sum(mid)<=target){
            ans = max(ans,mid);
            left = mid+1;
        }
        else    right = mid-1;
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int num;
    cin >> num;
    cout<<Find(num);
    return 0;
}
