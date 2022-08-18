#include <iostream>
#include <set>
#include <utility>
using namespace std;

int main(){
    int n, m;
    set<pair<int,int>> point;
    cin >> n >> m;

    int x,y;
    for(int i=0;i<n;i++){
        cin >> x >> y;
        point.insert(make_pair(x,y));
    }

    //map<string, int>::iterator it;
    for(int j=0;j<m;j++){
        cin >> x >> y;
        set<pair<int,int>>::iterator tmp = point.lower_bound(make_pair(x,y)); 
        if(tmp==point.end())  cout<<-1<<' '<<-1<<endl;
        else    cout<<(tmp -> first)<<' '<<(tmp->second)<<endl;
    }
    return 0;
}
