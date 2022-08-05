#include <iostream>
#include <map>
using namespace std;
#define MAX_NM 1000000
int main(){
    int n,m,mov;
    int arrA[MAX_NM] = {0},arrB[MAX_NM] = {0};
    char dir;

    map<char,int> d = {{'L',-1},{'R',1}};
    cin >> n >> m;

    int pos_n = 1, pos_m = 1;
    for(int i=1;i<=n;i++){
        cin >> dir >> mov;
        for(int j=0;j<mov;j++){
            arrA[pos_n] = arrA[pos_n-1] + d[dir];
            pos_n++;
        }
    }
    for(int i=1;i<=m;i++){
        cin >> dir >> mov;
        for(int j=0;j<mov;j++){
            arrB[pos_m] = arrB[pos_m-1] + d[dir];
            if(arrA[pos_m] == arrB[pos_m]){
                cout<<pos_m;
                return 0;
            }
            pos_m++;
        }
    }
    cout<<-1;
    return 0;

}
