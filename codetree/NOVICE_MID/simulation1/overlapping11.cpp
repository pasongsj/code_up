#include <iostream>
#define MAX_N 201
using namespace std;

int arr[MAX_N][MAX_N];
void paint(int x1,int y1,int x2,int y2,int c){
    for(int i=x1;i<x2;i++){
        for(int j=y1;j<y2;j++){
            arr[i][j] = c;
        }
    }
}
int main(){
    int n;
    cin >> n;
    int color = 1;
    for(int i=0;i<n;i++){
        int x1,y1, x2,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        paint(x1+100,y1+100,x2+100,y2+100,color);
        color *=-1;
    }
    int answer = 0;
    for(int i=0;i<MAX_N;i++){
        for(int j=0;j<MAX_N;j++){
            if(arr[i][j] == -1) answer ++;
        }
    }
    cout<<answer;
    return 0;
}
