#include <iostream>
using namespace std;
int main(){
    char a[6] = {'L', 'E', 'B', 'R', 'O', 'S'};
    int idx = -1;
    char b;
    cin >> b;
    for(int i=0;i<6;i++){
        if(a[i]==b){
            idx = i;
            break;
        }
    }
    if(idx==-1) cout<<"None";
    else    cout<<idx;
    return 0;
}

