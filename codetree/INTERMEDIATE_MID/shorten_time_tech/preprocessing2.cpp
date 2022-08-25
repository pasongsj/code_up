#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(pair<int,int> a, pair<int,int> b){
    if(a.first == b.first)  return a.second>b.second;
    return a.first>b.first;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,k;
    cin >> n >> k;
    vector<pair<int,int>> arr;
    for(int i=1;i<=n;i++){
        int x;
        cin >> x;
        arr.push_back(make_pair(x,i));
    }
    sort(arr.begin(),arr.end(),cmp);

    int tmp_num = -1,tmp_pos = -1,ans = -1;
    for(int i=0;i<arr.size();i++){
        if(tmp_num != arr[i].first){
            tmp_num = arr[i].first;
        }

        else if(tmp_pos - arr[i].second<=k){
            ans = max(ans, tmp_num);
            break;
        }
        tmp_pos = arr[i].second;
    }
    cout<<ans;

    return 0;

}
