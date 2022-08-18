#include <iostream>
#include <set>
#include <climits>
#include <tuple>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,tmp,min_x,ans = INT_MAX;
    cin >> n;
    set<int> x = {0};
    set<int>::iterator it;
    for(int i=0;i<n;i++){
        cin >> tmp;
        tie(it,ignore) = x.insert(tmp);
        ans = min(ans,tmp-*prev(it));
        if(++it != x.end())   ans = min(ans,*it-tmp);
        cout<<ans<<endl;
    }
    return 0;
}
