#include <iostream>
#include <unordered_map>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    unordered_map<int,int> point;
    int n;
    cin >> n;

    for(int i=0;i<n;i++){
        int x,y;
        cin >> x >> y;
        if(point.find(x)==point.end())  point[x] = y;
        else    point[x] = min(point[x],y);
    }

    unordered_map<int,int>::iterator it;
    long long ans = 0;
    for(it = point.begin();it != point.end();it++){
        ans+=it->second;
    }

    cout << ans;
    return 0;

}
