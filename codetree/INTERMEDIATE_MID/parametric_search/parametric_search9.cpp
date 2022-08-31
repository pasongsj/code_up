#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;

int n;
vector<pair<long long, long long>> line;

bool possible(long long num){

    long long before = line[0].first;
    for(int j=1;j<n;j++){
        long long x1,x2;
        tie(x1,x2) = line[j];
        if(before+num>x2)   return false;
        before = max(before+num,x1);
    }
    return true;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for(int i=0;i<n;i++){
        long long x1,x2;
        cin >> x1 >> x2;
        line.push_back(make_pair(x1,x2));
    }
    sort(line.begin(),line.end());
    
    long long left = 1, right = 1e9, ans = 0;
    while(left <= right){
        long long mid = (left + right)/2;
        if(possible(mid)){
            left = mid + 1;
            ans = max(ans,mid);
        }
        else    right = mid - 1;
    }
    cout<<ans;
    return 0;
    
}
