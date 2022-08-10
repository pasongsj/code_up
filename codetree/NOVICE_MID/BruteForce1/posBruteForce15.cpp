#include <iostream>
using namespace std;
#define MAX_N 20
int n;
int arr[MAX_N][MAX_N];
int main(){
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> arr[i][j];
        }
    }
    int tmp,ans = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n-2;j++){
            for(int k=i;k<n;k++){
                for(int l=j;l<n-2;l++){
                    if(i==k && j+2>=l)  continue;
                    tmp = arr[i][j] + arr[i][j+1] + arr[i][j+2] + arr[k][l] + arr[k][l+1] + arr[k][l+2];
                    ans = max(ans,tmp);
                }
            }
        }
    }
    cout<< ans;
    return 0;
}
