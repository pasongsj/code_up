#include <iostream>
#include <string>
using namespace std;
#define MAX_N 100000

int arr[MAX_N];
int main(){

    string s;
    cin >> s;
    for(int i=s.size()-2;i>=0;i--){
        arr[i]=arr[i+1];
        if(s[i]==')' && s[i+1] == ')')   arr[i]++;
    }
    long long int ans = 0;
    for(int i=0;i<s.size()-2;i++){
        if(s[i] == '(' && s[i+1] == '(')    ans+=arr[i+2];
        
    }
    cout<<ans;

    return 0;

}
