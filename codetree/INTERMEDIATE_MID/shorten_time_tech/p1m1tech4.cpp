#include <iostream>
#include <unordered_map>
#include <map>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,k;
    map<int,int> point;
    cin >> n >> k;

    unordered_map<int,int> d = {{'R',1},{'L',-1}};
    char dir;
    int len, now = 0;
    for(int i=0;i<n;i++){
        cin >> len >> dir;
        point[now] += d[dir];
        point[now + d[dir]*len] -= d[dir];
        now += d[dir]*len;

    }

    int ans = 0, cnt = 0;
    map<int,int>::iterator it;
    for(it = point.begin();it!=point.end();it++){
        cnt += (*it).second;
        if(cnt>=k){
            ans+= (*next(it)).first -(*it).first;
        }

    }
    cout<<ans;
    return 0;
}


