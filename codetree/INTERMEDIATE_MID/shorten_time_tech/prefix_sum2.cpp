#include <iostream>
using namespace std;
#define MAX_N 501

int arr[MAX_N][MAX_N];
int ans[MAX_N][MAX_N];

int n, k;

void init_ans(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            ans[i][j] = ans[i][j-1]+ans[i-1][j]-ans[i-1][j-1]+arr[i][j];
        }
    }
}

int find_max(){
    int res= 0;

    for(int i=k;i<=n;i++){
        for(int j=k;j<=n;j++){
            int tmp = ans[i][j] - ans[i-k][j] - ans[i][j-k] + ans[i-k][j-k];
            res = max(res,tmp);
        }
    }
    return res;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> k;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>arr[i][j];
        }
    }

    init_ans();
    cout<<find_max();
    
    return 0;
}
