#include <iostream>
using namespace std;
int main(){
    int n;
    int m[9]={0,};
    cin >> n;
    while(n!=0){
        if(n/10>0)  m[n/10-1]++;
        cin >> n;
    }
    for(int i=0;i<9;i++){
        cout<<i+1<<" - "<<m[i]<<endl;
    }
    return 0;
}
