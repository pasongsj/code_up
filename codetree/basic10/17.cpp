#include <iostream>
using namespace std;
bool is_exist(int a,int b){
    if(a==2){
        if(0<b&&b<=28)  return true;
    }
    else if(a<8&&a%2==1 || 8<=a && a%2==0 && a<13){
        if(0<b&&b<=31)  return true;
    }
    else if(a<8&&a%2==0 || 8<=a && a%2==1 && a<12){
        if(0<b&&b<=30)  return true;
    }
    return false;//4 6 9 11
}
int main(){
    int m,d;
    cin >> m >> d;
    if(is_exist(m,d))    cout<<"Yes";
    else    cout<<"No";
    return 0;
}
