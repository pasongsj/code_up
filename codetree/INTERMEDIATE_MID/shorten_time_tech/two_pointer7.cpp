#include <iostream>
#include <map>
#include <algorithm>
using namespace std;
#define MAX_N 2000000


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    map<int,int> baskets;
    for(int i=0;i<n;i++){
        int candy, pos;
        cin >> candy >> pos;
        baskets[pos]+=candy;
    }
    int ans = 0,sum = 0;

    map<int,int>::iterator L = baskets.begin();
    map<int,int>::iterator it;
    for(it = baskets.begin(); it!=baskets.end();it++){
        while((*L).first <= (*it).first+2*k && L!=baskets.end()){
            sum += (*L).second;
            L++;
        }
        ans = max(ans,sum);
        sum -= (*it).second;
    }
    cout<<ans;
    return 0;
}
