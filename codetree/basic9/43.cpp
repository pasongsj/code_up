#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
int main(){
    string s;
    int q,req;
    cin >> s >> q;
    for(int i=0;i<q;i++){
        cin>>req;
        if(req == 1)    s = s.substr(1,s.length()-1) + s[0];//요청1
        else if(req == 2)s = s[s.length()-1] + s.substr(0,s.length()-1); //요청2
        else    reverse(s.begin(), s.end());// 요청3
        cout<< s << endl;
    }
    return 0;
}
