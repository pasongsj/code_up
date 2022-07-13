#include <iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    int arr[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if((n-j)%2==0)  arr[i][j] = (n-j-1)*n + i + 1;
            else     arr[i][j] = (n-j)*n - i;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)    cout<<arr[i][j]<<' ';
        cout<<endl;
    }
    return 0;
}
