#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

//#define MAX_N 100001
vector<tuple <int,int,int>> arr;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,q;
    cin >> n >> q;

    arr.push_back(make_tuple(0,0,0));
    for(int i=1;i<=n;i++){
        int x,y,z,tmp;
        cin >> tmp;
        tie(x,y,z) = arr[i-1];
        if(tmp == 1)    x++;
        else if(tmp == 2)   y++;
        else    z++;
        arr.push_back(make_tuple(x,y,z));
    }

    for(int i=0;i<q;i++){
        int a,b;
        cin>> a >> b;
        int x1,y1,z1;
        int x2,y2,z2;
        tie(x1,y1,z1) = arr[a-1];
        tie(x2,y2,z2) = arr[b];
        cout<<x2-x1<<' '<<y2-y1<<' '<<z2-z1<<'\n';

    }

    return 0;
}
