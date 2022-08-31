#include <iostream>
#include <climits>
#include <vector>
#include <tuple>
#include <algorithm>
#include <set>
#include <unordered_set>
using namespace std;
int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n;
    cin >> n;
    vector<tuple<int,int,int,int>> point;
    for(int i=0;i<n;i++){
        int y, x1, x2;
        cin >> y >> x1 >> x2;
        point.push_back(make_tuple(x1,y,+1,i));
        point.push_back(make_tuple(x2,y,-1,i));
    }
    sort(point.begin(),point.end());

    set<pair<int,int>>colors;
    unordered_set<int> ans;
    int cur_y = INT_MAX;
    for(int i=0;i<point.size();i++){
        int x,y,p,index;
        tie(x,y,p,index) = point[i];
        if(p == 1){
            colors.insert(make_pair(y,index));
            if(cur_y>y){
                cur_y = y;
                ans.insert(index);
            }
        }
        else if(p==-1){
            colors.erase(make_pair(y,index));
            if(cur_y == y){
                if(colors.empty()){
                    y = INT_MAX;
                }
                else{   
                    int y2,index2;
                    tie(y2,index2) = *colors.begin();
                    cur_y = y2;
                    ans.insert(index2);
                }
            }

        }
       
    }
    cout<<ans.size();
    return 0;
}
