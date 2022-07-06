#include<iostream>
using namespace std;
int main(){
    int n,cnt = 0,num = 1;
    cin >> n;
    while(cnt<n*n){
        if(num==10) num=1;
        cout<<num;
        cnt++;
        num++;
        if(cnt%n==0)    cout<<endl;

    }
    return 0;
}
