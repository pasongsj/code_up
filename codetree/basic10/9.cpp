#include <iostream>
using namespace std;
bool is_369(int n){
    int tmp;
    if(n%3==0)  return true;
    while(n>0){
        if((n%10)%3==0&& n%10!=0) return true;
        n /= 10;
    }
    return false; 
}
int main(){
    int a,b,result = 0;
    cin >> a >> b;
    for(int i=a;i<=b;i++){
        if(is_369(i)==true) result ++;
    }
    cout << result;
    return 0;
}
