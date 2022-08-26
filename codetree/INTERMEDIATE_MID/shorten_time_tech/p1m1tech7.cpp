#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;
int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n;
    cin >> n;

    vector<pair<int,int>>arr;
    for(int i=0;i<n;i++){
        int a,b;
        cin >> a >> b;
        arr.push_back(make_pair(a,+1));
        arr.push_back(make_pair(b,-1));
    }

    sort(arr.begin(),arr.end());

    long long int ans = 0, cnt = 0,last = 0;
    for(int i=0;i<arr.size();i++){
        cnt += arr[i].second;
        if(last == 0 && cnt>0)   last = arr[i].first;
        else if(cnt<=0 && last !=0){
            ans = max((arr[i].first-last),ans);
            last = 0;
        }
    }
    cout<<ans;
    return 0;
}
