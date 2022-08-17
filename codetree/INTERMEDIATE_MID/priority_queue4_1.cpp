#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin >> n >>m;
    priority_queue <tuple<int,int,int>> point;
    for(int i=0;i<n;i++){
        int x,y;
        cin >> x >> y;
        point.push(make_tuple(-(x+y),-x,-y));
    }

    for(int i=0;i<m;i++){
        int sum,x,y;
        tuple<int,int,int> it = point.top();
        tie(sum,x,y) = it;
        point.pop();
        point.push(make_tuple((x+y)-4,x-2,y-2));
    }
    int sum,x,y;
    tuple<int,int,int> it = point.top();
    tie(sum,x,y) = it;
    cout<<-x<<' '<<-y;
    return 0;
}

