#include <iostream>
#include <string>
using namespace std;
int main(){
    string str1,str2,str3,str4;
    cin>> str1 >> str2;
    str3 = str1 + str2;
    str4 = str2 + str1;
    if(str3 == str4)    cout<<"true";
    else    cout<<"false";
    return 0;
}
