#include <iostream>
using namespace std;
int main(){
    int arr[3][3];
    int tmp;
    for(int i=0;i<3;i++)    for(int j=0;j<3;j++)    arr[i][j] = 1;
    for(int a=0;a<2;a++){
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                cin >> tmp;
                arr[i][j] *= tmp;
            }
        }
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cout<<arr[i][j]<<' ';
        }
        cout<<endl;

