#include <iostream>
using namespace std;
int main(){
    int m, n, cnt;
    cin >> m;
    for(int i=0;i<m;i++){
        cin >> n;
        cnt = 0;
        while(n!=1){
            if(n%2==1)  n = 3*n+1;
            else    n /= 2;
            cnt ++;
        }
        cout<<cnt<<endl;
    }
    return 0;
}
