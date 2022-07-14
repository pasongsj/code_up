#include <iostream>
#include <string>
using namespace std;
int main(){
    int n = 0, m = 0;
    string str;
    cin >> str;
    for(int i=0;i<str.length()-1;i++){
        if(str[i]=='e'&&str[i+1]=='e')   n++;
        if(str[i]=='e'&&str[i+1]=='b')   m++;

    }
    cout<<n<<' '<<m;
    return 0;
}
