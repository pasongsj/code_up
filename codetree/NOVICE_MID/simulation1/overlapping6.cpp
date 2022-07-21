#include <iostream>
using namespace std;

#define MAX_R 2000
#define OFFSET 1000
int arr[MAX_R][MAX_R];
int main(){

    int x1,y1,x2,y2;
    int index = 1;
    for(int i=0;i<3;i++){
        cin >> x1 >> y1 >>x2 >> y2;
        if(i==2)    index = 0;
        for(int i=x1+OFFSET;i<x2+OFFSET;i++){
            for(int j=y1+OFFSET;j<y2+OFFSET;j++){
                arr[i][j] = index;
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

