#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
using namespace std;

int n, m, ans, ans2;

vector<pair<int,int>> point;
vector<pair<int,int>> picked_m;
vector<pair<int,int>> picked_2;
int cal2(){
    return pow(picked_2[0].first - picked_2[1].first,2)+pow(picked_2[0].second - picked_2[1].second,2);
}

void Choose_2(int cur_num,int index){
    if(cur_num == 3){
        ans2 = max(ans2,cal2());
    }
    for(int i=index;i<picked_m.size();i++){
        picked_2.push_back(picked_m[i]);
        Choose_2(cur_num+1,i+1);
        picked_2.pop_back();
    }
}

int cal_pick2(){
    ans2 = 0;
    Choose_2(1,0);
    
    return ans2;
}

void Choose(int cur_num,int index){
    if(cur_num == m+1){
        if(ans == 0)    ans = cal_pick2();
        else    ans = min(ans,cal_pick2());
        return;
    }
    for(int i=index;i<point.size();i++){
        picked_m.push_back(point[i]);
        Choose(cur_num+1,i+1);
        picked_m.pop_back();
    }
}

int main(){
    cin >> n >> m;
    int r,c;
    for(int i=0;i<n;i++){
        cin >> r >> c;
        point.push_back(make_pair(r,c));
    }
    ans = INT_MAX;
    Choose(1,0);
    cout<<ans;
    return 0;
}
