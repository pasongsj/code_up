#include <iostream>
using namespace std;
void PrintRect(int n, int m) {
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)    cout<<1;
        cout<<endl;
    }
}

int main(){
    int row,col;
    cin >> row >> col;
    PrintRect(row,col);
    return 0;
}
