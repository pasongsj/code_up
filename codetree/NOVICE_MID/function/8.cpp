#include <iostream>
using namespace std;
bool is_num(int n){
    int sum = 0;
    while(n>0){
        sum += n%10;
        n /= 10;
    }
    if(sum%5==0)    return true;
    else    return false;
}
int main(){
    int num;
    cin >> num;
    if(is_num(num)==true)   cout<<"Yes";
    else    cout<<"No";
    return 0;
}
