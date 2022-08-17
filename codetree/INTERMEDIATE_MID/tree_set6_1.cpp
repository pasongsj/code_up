#include <iostream>
#include <set>
#include <climits>
using namespace std;

int main(){
    int n,tmp,min_x,ans = INT_MAX;
    cin >> n;

    set<int> x;
    x.insert(0);

    set<int>::iterator it;
    for(int i=0;i<n;i++){
        cin >> tmp;
        x.insert(tmp);
        it = x.upper_bound(tmp);
        if(it==x.end())   min_x  = *(--it)-*(--it);
        else    min_x = min(*(it)-*(--it),*(it)-*(--it));
        ans = min(ans,min_x);
        cout<<ans<<endl;
    }
    return 0;
}
