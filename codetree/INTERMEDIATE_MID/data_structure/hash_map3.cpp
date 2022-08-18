#include <iostream>
#include <unordered_map>
using namespace std;
int main(){
    unordered_map<string,int> d;
    int n, ans = 0;
    cin >> n;
    for(int i=0;i<n;i++){
        string s;
        cin >> s;
        d[s]++;
        ans = max(d[s],ans);
    }
    cout<<ans;
    return 0;

}
