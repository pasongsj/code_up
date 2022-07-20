#include <iostream>
#include <string>
using namespace std;
int main(){
    int cnt = 0;
    char tmp;
    string str;
    getline(cin,str);
    cin >> tmp;
    for(int i=0;i<str.length();i++){
        if(str[i]==tmp) cnt++;
    }
    cout<<cnt;
    return 0;
}
