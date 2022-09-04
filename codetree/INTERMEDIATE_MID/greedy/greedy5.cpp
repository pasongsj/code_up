#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
bool cmp(pair<int,int>a, pair<int,int>b){
    if(a.second==b.second)  return a.first>b.first;
    return a.second<b.second;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n;
    cin >> n;
    vector<pair<int,int>> meeting;
    for(int i=0;i<n;i++){
        int start,end;
        cin >> start >> end;
        meeting.push_back(make_pair(start,end));
    }
    sort(meeting.begin(),meeting.end(),cmp);

    int ans= 0, is_end = 0;
    for(int i=0;i<n;i++){
        if(is_end<=meeting[i].first){
            is_end = meeting[i].second;
            ans++;
        }
    }
    cout<<ans;
    return 0;

}
