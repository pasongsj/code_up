#include <iostream>
#include <string>
using namespace std;
int main(){
    string a,b;
    int cnt = 1;
    cin >> a >> b;
    int len_a = a.length(), len_b = b.length();
    while(cnt > 0){
        cnt = 0;
        for(int i=0;i<=len_a-len_b;i++){
            if(a.substr(i,len_b).compare(b)==0){
                a.erase(i,len_b);
                cnt ++;
                len_a -= len_b;
            }
        }
    }
    cout<<a;
    return 0;
}
