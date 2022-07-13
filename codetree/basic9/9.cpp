#include <iostream>
#include <string>
using namespace std;
int main(){
    string str[4];
    for(int i=0;i<4;i++)    cin>>str[i];
    for(int j=3;j>=0;j--)   cout<<str[j]<<endl;
    return 0;
}
