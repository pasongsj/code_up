#include <iostream>
#include <string>
using namespace std;
int main(){
    string str;
    cin >> str;
    bool ee = false, ab = false;
    for(int i=0;i<str.length()-1;i++){
        if(str[i]=='e'&&str[i+1]=='e')  ee = true;
        if(str[i]=='a'&&str[i+1]=='b')  ab = true;
    }
    if(ee)  cout<<"Yes"<<' ';
    else    cout<<"No"<<' ';
    if(ab)  cout<<"Yes"<<' ';
    else    cout<<"No"<<' ';
    return 0;
}
