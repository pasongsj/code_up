#include <iostream>
#include <map>
using namespace std;
//#define MAX_N 1000000000



int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    map<int,int> point;
    for(int i=0;i<n;i++){
        int a,b;
        cin >> a >> b;
        point[a]++;
        point[b]--;

    }
    map<int,int>:: iterator it;
    int ans = 0,tmp = 0;
    for(it = point.begin();it!=point.end();it++){
        tmp +=(*it).second;
        if(tmp == 0){
            ans++;
        }
    }
    cout<<ans;
    return 0;

}
