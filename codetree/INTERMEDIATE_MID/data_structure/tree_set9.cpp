#include <iostream>
#include <set>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin >> n >> m;

    set<int> chair;
    for(int i=1;i<=m;i++)   chair.insert(-i);

    int ans = 0;


    for(int i=0;i<n;i++){
        int tmp;
        cin >> tmp;
        set<int>::iterator it = chair.lower_bound(-tmp);
        if(it!=chair.end()){
            ans++;
            chair.erase(*it);
            continue;
        }
        break;
    }
    cout<<ans;
    return 0;
}
