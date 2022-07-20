#include <iostream>
using namespace std;
int main(){
    char arr[5][3];
    for(int x=0;x<5;x++)    for(int y=0;y<3;y++)    cin>>arr[x][y];
    for(int x=0;x<5;x++){
        for(int y=0;y<3;y++)    cout<<(char)toupper(arr[x][y])<<' ';
        cout<<endl;
    }
    return 0;
}

