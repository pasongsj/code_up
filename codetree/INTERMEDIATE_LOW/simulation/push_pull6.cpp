#include <iostream>
#include <string>
using namespace std;

int run_length_encoding(string s){
    string ans;
    int cnt = 1;
    char a = s[0];
    for(int i=1;i<s.length();i++){
        if(a == s[i])   cnt++;
        else{
            ans+=(a+to_string(cnt));
            cnt = 1;
            a = s[i];
        }
    }
    ans += (a+to_string(cnt));
    return ans.length();
}

int main(){
    int len,tmp,result = 20;
    char last;
    string str;
    cin >> str;
    len = str.length();
    for(int i=0;i<len;i++){
        tmp = run_length_encoding(str);
        if(tmp<result)  result = tmp;
        last = str[len-1];
        for(int j=len-1;j>0;j--){
            str[j] = str[j-1];
        }
        str[0] = last;
    }
    cout<<result;
    return 0;

}
