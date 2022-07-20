#include<iostream>
using namespace std;
int main(){
    int n,m;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> m;
        if(m%3==0 && m%2==1)    cout<<m<<endl;
    }
    return 0;
}
