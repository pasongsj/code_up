#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;
int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n;
    cin >> n;
    vector<pair<int,int>> arr;
    for(int i=0;i<n;i++){
        int a,b;
        cin >> a >> b;
        arr.push_back(make_pair(a,1));
        arr.push_back(make_pair(b,-1));
    }
    sort(arr.begin(),arr.end());

    long cnt = arr[0].second, ans = 0, before = 0;
    for(int i=1;i<arr.size();i++){
        if(cnt>0) 
            ans += arr[i].first - arr[i-1].first;
        cnt += arr[i].second;
    }
    cout<<ans;
    return 0;
}
