#include<iostream>
using namespace std;
int main(){
    int n,tmp;
    cin >> n;
    for(int i=1;i<=n;i++){
        tmp = i;
        while(tmp>0){
            if(tmp%3==0|| (tmp%10)%3==0 && tmp%10 > 0){
                cout<<0<<' ';
                break;
            }
            tmp/=10;
        }
        if(tmp==0)  cout<<i<<' ';
    }
    return 0;
}
