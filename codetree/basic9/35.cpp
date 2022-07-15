#include <iostream>
#include <string>
using namespace std;
int main(){
    string s;
    int q,num,a,b;
    char tmp,t1,t2;
    cin >> s >> q;
    for(int i=0;i<q;i++){
        cin >> num;
        if(num == 1){
            cin >> a >> b;
            tmp = s[a-1];
            s[a-1] = s[b-1];
            s[b-1] = tmp;
        }
        else{
            cin >> t1 >> t2;
            for(int j=0;j<s.length();j++){
                if(s[j]==t1)  s[j] = t2;
            }
        }
        cout<<s<<endl;
    }
    return 0;
}
