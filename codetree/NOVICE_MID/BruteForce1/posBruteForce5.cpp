#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

#define MAX_RC 15
char arr[MAX_RC][MAX_RC];

int main(){
    int r,c;
    cin >> r >> c;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>arr[i][j];
        }
    }

    char stone = arr[0][0];
    int ans = 0;
    for(int i=1;i<r-1;i++){
        for(int j=1;j<c-1;j++){
            for(int k=i+1;k<r-1;k++){
                for(int l=j+1;l<c-1;l++){
                    if(stone != arr[i][j] && stone == arr[k][l] && stone!=arr[r-1][c-1])    ans++;
                }
            }
        }
    }
    cout<<ans;
    return 0;
}
