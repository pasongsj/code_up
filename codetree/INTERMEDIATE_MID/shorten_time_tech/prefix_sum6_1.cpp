#include <iostream>
#include <climits>
#include <set>
#include <unordered_map>
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,q,max_n = 0;
    cin >> n >> q;
    set<int>point;
    for(int i=0;i<n;i++){
        int tmp;
        cin >> tmp;
        point.insert(tmp);
    }

    unordered_map<int,int>arr;
    set<int>::iterator it;
    int before = 0;
    for(it = point.begin();it!=point.end();it++){
        arr[(*it)] = ++before;
    }
    for(int i=0;i<q;i++){
        int a,b;
        cin >> a >> b;
        int x,y;
        if(point.upper_bound(b) == point.end()) x = before;
        else    x = arr[*point.upper_bound(b)]-1;

        if(point.lower_bound(a) == point.end()) y = before;
        else    y = arr[*point.lower_bound(a)]-1;
        cout<<x-y<<'\n';
        
    }

    return 0;
}
