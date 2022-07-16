#include <iostream>
#include <string>
using namespace std;
int main(){
    string s[200];
    int cnt = 0;
    while (true){
        cin >> s[cnt];
        if(s[cnt]=="0") break;
        cnt++;
    }
    cout<<cnt<<endl;
    for(int i=0;i<cnt;i+=2){
        cout<<s[i]<<endl;
    }
    return 0;
}
