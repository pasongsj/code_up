#include <iostream>
#include <set>
#include <climits>
#define MAX_N 100000
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m,k;
    cin >> n >> m;

    set<pair<long long,long long>> point;
    for(int i=0;i<n;i++){
        long long x,y;
        cin >> x >> y;
        point.insert(make_pair(x,y));
    }

    for(int i=0;i<m;i++){
        long long k;
        cin >> k;
        auto it = point.upper_bound(make_pair(k,0));
        if(it == point.end())   cout<<-1<<' '<<-1<<'\n';
        else{
            cout<<(*it).first<<' '<<(*it).second<<'\n';
            point.erase(*it);
        }
    }

    
    return 0;
}
