#include <iostream>
using namespace std;

#define MAX_R 201
#define OFFSET 100
int arr[MAX_R][MAX_R];
int main(){
    int n,x,y;
    cin>>n;
    for(int i=0;i<n;i++){
        cin >> x >> y;
        for(int j=0;j<8;j++){
            for(int k=0;k<8;k++){
                arr[x+OFFSET+j][y+OFFSET+k] = 1;
            }
        }
    }
    int cnt = 0;
    for(int i=0;i<MAX_R;i++){
        for(int j=0;j<MAX_R;j++){
            if(arr[i][j]==1)    cnt++;
        }
    }
    cout<<cnt;
    return 0;
}
