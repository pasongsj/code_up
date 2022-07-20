#include <iostream>
#include <string>
using namespace std;

void is_palindrome(string &str) {
    bool is_pali = true;
    for(int i=0;i<=str.length()/2;i++){
        if(str[i]!=str[str.length()-i-1]){
            is_pali = false;
            break;
        }
    }
    if(is_pali) cout<<"Yes";
    else    cout<<"No";
}

int main() {
    string s;
    cin >> s;
    is_palindrome(s);
    return 0;
}
