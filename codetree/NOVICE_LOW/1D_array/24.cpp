#include <iostream>
using namespace std;
int main(){
    char a;
    int temp;
    int b[4]={0,};
    for(int i=0;i<3;i++){
        cin >> a >> temp;
        if(a=='Y'){
            if(temp>=37)    b[0]++;
            else    b[2]++;
        }
        else{
            if(temp>=37)    b[1]++;
            else    b[3]++;
        }
    }
    for(int j=0;j<4;j++)    cout<<b[j]<<' ';
    if(b[0]>=2) cout<<'E';
    return 0;
}

