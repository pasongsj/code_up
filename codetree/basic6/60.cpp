#include <iostream>
using namespace std;
int main(){
    int n,cnt = 0,is_prime=0;
    cin >> n;
    for(int i=2;i<=n;i++){
        is_prime = 0;
        if(i > 2){
            for(int j=2;j<=i/2;j++){
                if(i%j == 0){
                    is_prime = 1;
                    break;
                }
            }
        }
        if(is_prime == 0)   cout<<i<<' ';
    }
    return 0;
}
