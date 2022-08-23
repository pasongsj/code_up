#include <iostream>
using namespace std;
#define MAX_N 200001


int point[MAX_N];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    
    for(int i=0;i<n;i++){
        int a,b;
        cin >> a >> b;
        point[a]++;
        point[b]--;

    }

    int ans = 0, tmp = 0;
    for(int i=1;i<MAX_N;i++){
        tmp += point[i];
        ans = max(ans,tmp);
    }
    cout<<ans;
    return 0;

}
