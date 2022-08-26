#include <iostream>
#include <climits>
#include <algorithm>
#define MAX_N 100001

int fire_pos[MAX_N];
int station_pos[MAX_N];
using namespace std;
int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n,m;
    cin >> n >> m;

    for(int i=1;i<=n;i++){
        cin >> fire_pos[i];
    }
    for(int i=1;i<=m;i++){
        cin >> station_pos[i];
    }
    sort(fire_pos+1,fire_pos+n+1);
    sort(station_pos+1,station_pos+m+1);

    int ans = 0, L = 1;
    for(int i=1;i<=n;i++){
        while(L<m && abs(fire_pos[i]-station_pos[L])>abs(fire_pos[i]-station_pos[L+1])){
            L++;
        }
        ans = max(ans,abs(fire_pos[i] - station_pos[L]));
    }
    cout<<ans;
    return 0;

}
