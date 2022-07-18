#include <iostream>
using namespace std;
int main(){
    int n,m ,a,b,cnt;
    cin >> n >> m;
    int arr[n][n] = {};
    for(int i=0;i<m;i++){
        cnt = 0;
        cin >> a >> b;
        a--;
        b--;
        arr[a][b] = 1;
        if(a==0 && b!=0 && b!=n-1){
            if(arr[a][b-1]+arr[a+1][b] + arr[a][b+1]==3)    cnt = 1;
        }
        else if(a==n-1 && b!=0 && b!=n-1){
            if(arr[a][b-1]+arr[a-1][b] + arr[a][b+1]==3)    cnt = 1;
        }
        else if(b==0 && a!=0 && a!=n-1){
            if(arr[a-1][b]+ arr[a+1][b] + arr[a][b+1]==3)   cnt = 1;
        }
        else if(b==n-1 && a!=0 && a!=n-1){
            if(arr[a-1][b]+ arr[a+1][b] + arr[a][b-1]==3)   cnt = 1;
        }
        else if(b!=0 && b!=n-1 && a!=0 && a!=n-1){
            if(arr[a-1][b]+ arr[a+1][b] + arr[a][b-1]+arr[a][b+1]==3)   cnt = 1;
        }
        cout<<cnt<<endl;
    }
    
    return 0;
}
