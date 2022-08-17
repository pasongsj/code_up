#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

struct cmp {
    bool operator()(tuple<int,int, int> a, tuple<int,int, int> b) {
        int sum1,sum2,x1,x2,y1,y2;
        tie(sum1,x1,y1) = a;
        tie(sum2,x2,y2) = b;
        if(sum1==sum2){
            if(x1==x2)  return y1>y2;
            return x1>x2;
        }
        return sum1>sum2;

    }
};


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin >> n >>m;
    priority_queue <tuple<int,int,int>, vector<tuple<int,int,int>>, cmp> point;
    for(int i=0;i<n;i++){
        int x,y;
        cin >> x >> y;
        point.push(make_tuple(x+y,x,y));
    }

    for(int i=0;i<m;i++){
        int sum,x,y;
        tuple<int,int,int> it = point.top();
        tie(sum,x,y) = it;
        point.pop();
        point.push(make_tuple(x+y+4,x+2,y+2));
    }
    cout<<get<1>(point.top())<<' '<<get<2>(point.top());
    return 0;
}

