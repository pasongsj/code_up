#include<iostream>
using namespace std;
int main(){
    int n;
    int m[6]={0,};
    for(int i=0;i<10;i++){
        cin>>n;
        m[n-1]++;
    }
    for(int j=0;j<6;j++){
        cout<< j+1<<" - "<<m[j]<<endl;
    }
    return 0;
}
