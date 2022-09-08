#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;
#define MAX_T 10000


vector<pair<int,int>> bomb;
int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n,ans = 0;
    cin >> n;
    for(int i=0;i<n;i++){
        int score, time, tmp;
        cin >> score >> time;
        bomb.push_back(make_pair(time,score));
    }

    sort(bomb.begin(),bomb.end());

    int L=bomb.size()-1;
    priority_queue<int> score;
    for(int i=MAX_T;i>=1;i--){
        while(L>=0 && i<=bomb[L].first){
            score.push(bomb[L--].second);
        }

        if(!score.empty()){
            ans+= score.top();
            score.pop();
        }
    }

    cout<<ans;
    return 0;
}
