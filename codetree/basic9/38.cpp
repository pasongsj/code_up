#include <iostream>
#include <string>
using namespace std;
int main(){
    string s;
    cin >> s;
    int a,len = s.length();
    while(len>1){
        cin >> a;
        if(a>=len)    a = len-1;
        s.erase(a,1);
        cout<<s<<endl;
        len --;
    }
    return 0;
}
