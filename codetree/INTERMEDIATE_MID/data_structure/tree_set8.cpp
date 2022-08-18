#include <iostream>
#include <set>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin >> n >> m;
    set<int> arr;

    for(int i=0;i<n;i++){
        long long tmp;
        cin >> tmp;
        arr.insert(-tmp);
    }
    for(int i=0;i<m;i++){
        long long tmp;
        cin >> tmp;
        set<int>::iterator it = arr.lower_bound(-tmp);
        if(it!=arr.end()){
            cout<<-*it<<'\n';
            arr.erase(*it);
        }
        else    cout<<-1<<'\n';
    }
    return 0;
}
