#include<iostream>
using namespace std;
int main(){
    int n,tmp;
    cin >> n;
    int m[9] = { 0,};
    for(int i=0;i<n;i++){
        cin>>tmp;
        m[tmp-1]++;
    }
    for(int j=0;j<9;j++)    cout<<m[j]<<endl;
}
