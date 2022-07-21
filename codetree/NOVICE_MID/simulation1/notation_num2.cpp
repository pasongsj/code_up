#include <iostream>
#include <string>
using namespace std;
int main(){
    string n;
    cin>>n;
    int ans = 0;

    for(int i=0;i<n.length();i++){
        ans = ans*2 + (int)(n[i]-'0');
    }
    cout<<ans;
    return 0;
}
