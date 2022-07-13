#include <iostream>
using namespace std;
int main(){
    int arr[4][4];
    int sum = 0;
    for(int x=0;x<4;x++)    for(int y=0;y<4;y++)    cin>>arr[x][y];
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(i>=j)    sum+= arr[i][j];
        }
    }
    cout<<sum;
    return 0;
}
