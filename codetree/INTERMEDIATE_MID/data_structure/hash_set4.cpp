#include <iostream>
#include <unordered_set>

using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin >> n;
    unordered_set<int> arr;

    for(int i=1;i<=n;i++){
        int tmp;
        cin >> tmp;
        arr.insert(tmp);
    }
    cin >> m;
    for(int i=0;i<m;i++){
        int tmp;
        cin >> tmp;
        if(arr.find(tmp)==arr.end())    cout<<0<<'\n';
        else    cout<<1<<'\n';
    }

    return 0;
}

