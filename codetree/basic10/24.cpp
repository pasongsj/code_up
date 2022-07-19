#include <iostream>
#include <string>
using namespace std;

string s,t;

int pos_str(){
    if(s.find(t) != string::npos)   return s.find(t);
    return -1;
}

int main(){
    cin >> s >>t;
    cout<<pos_str();
    return 0;
}
