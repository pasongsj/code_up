#include <iostream>
using namespace std;
bool is_com(int n){
    if(n%2 == 0)    return false;
    if(n%10 == 5)   return false;
    if(n%3 ==0 && n%9!=0)  return false;
    return true;
}
int main(){
    int a,b,cnt = 0;
    cin >> a >> b;
    for(int i=a;i<=b;i++){
        if(is_com(i))   cnt++;
    }
    cout<<cnt;
    return 0;
}
