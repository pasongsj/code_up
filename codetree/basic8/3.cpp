#include <iostream>
using namespace std;
int main(){
    int arr[2][4];
    int sum;
    cout<<fixed;
    cout.precision(1);
    for(int i=0;i<2;i++)    for(int j=0;j<4;j++)    cin>>arr[i][j];
    //가로평균
    for(int x=0;x<2;x++){
        sum = 0;
        for(int y=0;y<4;y++)    sum += arr[x][y];
        cout<<(double)sum/4<<' ';
    }
    cout<<endl;
    //세로평균
    for(int y=0;y<4;y++){
        sum = 0;
        for(int x=0;x<2;x++)    sum += arr[x][y];
        cout<<(double)sum/2<<' ';
    }
    cout<<endl;
    // 전체평균
    sum = 0;
    for(int x=0;x<2;x++)    for(int y=0;y<4;y++)    sum += arr[x][y];
    cout<<(double)sum/8;
    return 0;
}
