#include <iostream>
using namespace std;
int arr[20][20];
int rhom[20][20];
int n;

int rhombus(int x,int y,int k){
    int cnt = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(abs(x-i)+abs(y-j)<=k){
                cnt += arr[i][j];
            }
        }
    }
    return cnt;
}

int cost(int k){
    return k*k + (k+1)*(k+1);
}


int main(){
    int m;
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)    cin>>arr[i][j];
    }
    int tmp,ans = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<2*n-1;k++){
                tmp = rhombus(i,j,k);
                if(m*tmp - cost(k)>=0 && tmp>ans)    ans = tmp;
            }
        }
    }
    cout<<ans;
    return 0;


}



