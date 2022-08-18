#include <iostream>
#include <unordered_set>

using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin >> n >> m;
    unordered_set<int> arr;
    int ans = n+m;

    for(int i=0;i<n;i++){
        int tmp;
        cin >> tmp;
        arr.insert(tmp);
    }
    for(int i=0;i<m;i++){
        int tmp;
        cin >> tmp;
        if(arr.find(tmp)!=arr.end())  ans -= 2;
    }
    cout<<ans;

    return 0;
}

