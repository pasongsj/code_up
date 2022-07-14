#include <iostream>
#include <string>
using namespace std;
int main(){
    int n;
    string tmp, str;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> tmp;
        str += tmp;
    }
    for(int i=0;i<str.length();i++){
        if(i%5==0 && i!=0)  cout<<endl;
        cout<<str[i];
    }
    return 0;
}
