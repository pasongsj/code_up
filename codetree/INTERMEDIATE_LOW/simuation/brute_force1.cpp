#include <iostream>
using namespace std;

int arr[20][20];

int sum(int x,int y){
    int ans = 0;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            ans += arr[x+i][y+j];
        }
    }
    return ans;
}

int main(){
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        for (int j=0;j<n;j++)   cin >> arr[i][j];
    }
    int tmp,max = 0;
    for(int i=0;i<n-2;i++){
        for(int j=0;j<n-2;j++){
            tmp = sum(i,j);
            if(tmp>max) max =tmp;
        }
    }
    cout<<max;
    return 0;
}

