#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>
#include <tuple>
using namespace std;

int main(){
    int n,k;
    cin >> n >> k;
    unordered_map <int,int>arr;
    for(int i=0;i<n;i++){
        int tmp;
        cin >> tmp;
        arr[tmp]++;
    }

    unordered_map<int,int>::iterator it;
    vector<pair<int,int>> ans;
    for(it = arr.begin();it !=arr.end();it++){
        ans.push_back(make_pair(-(it->second),-(it->first)));
    }
    sort(ans.begin(),ans.end());
    for(int i=0;i<k;i++)    cout<<-ans[i].second<<' ';

    return 0;
}
