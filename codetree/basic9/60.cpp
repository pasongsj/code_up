#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main(){
    string s;
    while (true){
        cin >> s;
        if(s == "END")  break;
        reverse(s.begin(),s.end());
        cout << s << endl;
    }
    return 0;
}
