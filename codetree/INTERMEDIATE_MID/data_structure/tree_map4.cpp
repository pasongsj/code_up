#include <iostream>
#include <map>
#include <string>

using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    map<int,int> arr;
    for(int i=1;i<=n;i++){
        int tmp;
        cin >> tmp;
        arr.insert({tmp,i});
    }

    map<int,int>::iterator it;
    for(it=arr.begin();it!=arr.end();it++)  cout<<it->first<<' '<<it->second<<'\n';

    return 0;
}

