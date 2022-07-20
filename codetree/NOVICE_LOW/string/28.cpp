#include <iostream>
#include <string>
using namespace std;
int main(){
    string str;
    char word;
    cin >> str>> word;
    if(str.find(word) != string::npos) cout<<str.find(word);
    else    cout<<"No";
    return 0;
}
