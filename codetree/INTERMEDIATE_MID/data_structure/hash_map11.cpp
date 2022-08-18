#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>

using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    unordered_map<char,int> arr;
    for(int i=0;i<s.length();i++){
        arr[s[i]]++;
    }
    unordered_map<char,int>::iterator it;
    for(it=arr.begin();it!=arr.end();it++){
        if(it->second == 1){
            cout<<it->first;
            return 0;
        }
    }
    cout<<"None";
    return 0;
}
