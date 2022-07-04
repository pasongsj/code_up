#include <iostream>
using namespace std;
int main(){
    int n;
    for(int i=0;i<5;i++){
        cin>>n;
        if(n%3!=0){
            cout<<0;
            return 0;
        }
    }
    cout<<1;
    return 0;
}
