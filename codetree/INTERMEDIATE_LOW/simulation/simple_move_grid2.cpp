#include <iostream>
using namespace std;
int arr[100][100];
int n,m,k;

int find_row(){
    for(int i=0;i<n;i++){
        for(int j=k-1;j<(m-1)+k;j++){
            if(arr[i][j]!=0){
                return i-1;
            }
        }
    }
    return n-1;
}

int main(){
    cin >> n >> m >> k;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)    cin>>arr[i][j];
    }
    //row
    int row = find_row();
    //insert
    for(int j=k-1;j<m-1+k;j++){
        arr[row][j] = 1;
    }
    //print
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)    cout<<arr[i][j]<<' ';
        cout<<endl;
    }
    return 0;
}
