#include <iostream>
#include <map>
#include <string>

using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    map<string,int> arr;
    for(int i=0;i<n;i++){
        string s;
        cin >> s;
        arr[s]++;
    }

    map<string,int>::iterator it;
    for(it=arr.begin();it!=arr.end();it++){
        cout<<it->first<<' '<<it->second<<'\n';
    }

    return 0;
}
