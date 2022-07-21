#include <iostream>
#define MAX_R 200
#define OFFSET 100

using namespace std;
int main(){
    int n,x1,y1,x2,y2;
    int arr[MAX_R][MAX_R]={};
    cin >> n;
    for(int i=0;i<n;i++){
        cin >>x1>>y1>>x2>>y2;
        for(int i=x1+OFFSET;i<x2+OFFSET;i++){
            for(int j=y1+OFFSET;j<y2+OFFSET;j++){
                arr[i][j]++;
            }
        }
    }
    int cnt = 0;
    for(int i=0;i<MAX_R;i++){
        for(int j=0;j<MAX_R;j++){
            if(arr[i][j]>0) cnt++;
        }
    }
    cout<<cnt;
    return 0;
}
