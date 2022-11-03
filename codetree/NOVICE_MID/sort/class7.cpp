#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n;
    cin >> n;
    cin.ignore();
    vector<string> ans;

    for(int i=0;i<n;i++){
        string tmp;
        getline(cin,tmp);
        if(tmp.substr(15) == "Rain")    ans.push_back(tmp);
    }
    sort(ans.begin(),ans.end());
    cout<<ans[0];
    return 0;
}
