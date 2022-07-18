#include <iostream>
using namespace std;
int main(){
    int n, pos_x = 0,pos_y = 0,max_val1 = 0,max_val2 = 0;
    cin >> n;
    int arr[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)    cin >> arr[i][j];
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n-2;j++){
            if(arr[i][j] + arr[i][j+1] + arr[i][j+2] >= max_val1){
                pos_x = i;
                pos_y = j;
                max_val1 = arr[i][j] + arr[i][j+1] + arr[i][j+2];
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n-2;j++){
            if(arr[i][j] + arr[i][j+1] + arr[i][j+2]> max_val2){
                if(pos_x == i && (pos_y>j+2 || pos_y+2<j)){
                    max_val2 = arr[i][j] + arr[i][j+1] + arr[i][j+2];
                }
                else if(pos_x != i) max_val2 = arr[i][j] + arr[i][j+1] + arr[i][j+2];
            }
        }
    }
    cout<< max_val1 + max_val2;
    return 0;
}
