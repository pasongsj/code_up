#include <iostream>
using namespace std;
bool is_year(int n){
    if(n%400==0)    return true;
    if(n%100==0)    return false;
    if(n%4==0)  return true;
    return false;
}
int main(){
    int a;
    cin >> a;
    if(is_year(a)==true)    cout<<"true";
    else    cout<<"false";
}
