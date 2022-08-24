#include <iostream>
#include <map>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    map<int,int> arr;
    cin >> n;

    for(int i=0;i<n;i++){
        int x,y;
        cin >> x >> y;
        arr[x]++;
        arr[y]--;
    }
    map<int,int>::iterator it;
    int ans = 0,tmp = 0;;
    for(it=arr.begin();it!=arr.end();it++){
        tmp += (*it).second;
        ans = max(ans, tmp);
    }
    cout<<ans;
    return 0;
}


