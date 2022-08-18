#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>

using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    unordered_map<string,int> arr;
    int n, ans = 0;
    cin >> n;

    for(int i=0;i<n;i++){
        string s;
        cin >> s;
        sort(s.begin(),s.end());
        arr[s]++;
        ans = max(arr[s],ans);
    }   
    cout << ans;
    return 0;

}
