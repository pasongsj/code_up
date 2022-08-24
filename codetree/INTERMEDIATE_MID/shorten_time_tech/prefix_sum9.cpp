#include <iostream>
using namespace std;
#define MAX_N 400
int n, k;

int in_range(int num){
    if(num<0)   return 0;
    if(num>n)   return n;
    return num;
}

bool is_range(int num){
    return (0<num && num<= n);
}

int arr[MAX_N+1][MAX_N+1];
int prefix_sum[MAX_N+1][MAX_N+1];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> arr[i][j];
            prefix_sum[i][j] = prefix_sum[i][j-1]+arr[i][j];
        }
    }

    int ans= 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            // i,j점에서 시작
            int tmp = prefix_sum[i][in_range(j+k)]-prefix_sum[i][in_range(j-k-1)];
            for(int a = 1;a<=k;a++){
                if(is_range(i-a)){
                    tmp += prefix_sum[i-a][in_range(j+(k-a))]-prefix_sum[i-a][in_range(j-(k-a)-1)];
                }
                if(is_range(i+a)){
                    tmp += prefix_sum[i+a][in_range(j+(k-a))] - prefix_sum[i+a][in_range(j-(k-a)-1)];
                }
            }
            ans = max(ans,tmp);
        }
    }
    cout<<ans;

    return 0;
}


