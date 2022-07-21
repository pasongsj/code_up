#include <iostream>
using namespace std;

#define MAX_R 2001
#define OFFSET 1000
int arr[MAX_R][MAX_R];

int main(){
    int x1,x2,y1,y2;
    cin >>x1>>y1>>x2>>y2;
    for(int i=x1;i<x2;i++){
        for(int j=y1;j<y2;j++){
            arr[i+OFFSET][j+OFFSET] = 1;
        }
    }
    cin >>x1>>y1>>x2>>y2;
    for(int i=x1;i<x2;i++){
        for(int j=y1;j<y2;j++){
            arr[i+OFFSET][j+OFFSET] = 0;
        }
    }
    int min_x = 2000,min_y =2000, max_x= 0,max_y = 0,cnt = 0;
    for(int i=0;i<MAX_R;i++){
        for(int j=0;j<MAX_R;j++){
            if(arr[i][j]==1){
                if(min_x>i) min_x = i;
                if(min_y>j) min_y = j;
                if(max_x<i) max_x = i;
                if(max_y<j) max_y = j;
                cnt ++;
            }
        }
    }
    if(cnt == 0)    cout<<0;
    else    cout<< (max_y-min_y+1)*(max_x-min_x+1);
    return 0;
}
