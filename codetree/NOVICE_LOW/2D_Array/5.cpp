#include <iostream>
using namespace std;
int main(){
    int a,b, cnt = 1;
    cin >> a >> b;
    int arr[a][b];
    for(int i=0;i<a;i++){
        for(int j=0;j<b;j++){
            arr[i][j]=cnt;
            cnt++;
        }
    }
    for(int x=0;x<a;x++){
        for(int y=0;y<b;y++){
            cout<<arr[x][y]<<' ';
        }
        cout<<endl;
    } 
    return 0;
}
