#include <iostream>
using namespace std;
#define MAX_N  1000
int main(){
    int n, first, tmp, cnt = 1, ans = 1;

    cin >> n >> first;

    for(int i=0;i<n-1;i++){
        cin >> tmp;
        if(tmp*first>0) cnt++;
        else{
            first = tmp;
            cnt = 1;
        }
        ans = max(ans,cnt);
    }
    cout << ans;
    return 0;   
}
