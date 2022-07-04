#include <iostream>
using namespace std;
int main(){
    int n, is_prime = 0;
    cin>>n;
    for(int i=2;i<n/2;i++){
        if(n%i==0){
            is_prime = 1;
            cout<<'C';
            break;
        }
    }
    if(is_prime == 0)   cout<<'N';
    return 0;
    }
