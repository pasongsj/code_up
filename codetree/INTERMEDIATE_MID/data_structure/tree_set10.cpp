#include <iostream>
#include <set>
#include <climits>
#define MAX_N 100000
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long m;
    cin >> n >> m;
    set<long long int>arr;
    for(int i=0;i<n;i++){
        long long int tmp;
        cin >> tmp;
        arr.insert(tmp);
    }
    //a-b>=m a>=m+b
    long long ans = INT_MAX;
    for(auto it = arr.begin();it!=arr.end();it++){
        if(arr.lower_bound(*it+m)!=arr.end())   ans = min(ans,*arr.lower_bound(*it+m)-*it);
    }

    if(ans == INT_MAX)  cout<<-1;
    else    cout<<ans;
    return 0;
}
