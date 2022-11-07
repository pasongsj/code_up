#include <iostream>
using namespace std;
int main(){
    int n,t;
    cin >> n >> t;
    int ans = 0, cnt = 0;
    for(int i=0;i<n;i++){
        int tmp;
        cin >> tmp;
        if(t<tmp)   cnt++;
        else{
            ans = max(ans,cnt);
            cnt = 0;
        }
    }
    cout<<ans;
    return 0;
}
