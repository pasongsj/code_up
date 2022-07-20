#include <iostream>
using namespace std;
int main(){
    int n,cnt = 1;
    cin >> n;
    int m[100];
    m[0] = 1;
    m[1] = n;
    while(m[cnt]<100){
        cnt++;
        m[cnt] = m[cnt-1]+m[cnt-2];
    }
    for(int i=0;i<cnt+1;i++)    cout<<m[i]<<' ';
    return 0; 
}
