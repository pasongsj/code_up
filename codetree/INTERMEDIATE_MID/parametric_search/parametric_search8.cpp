#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

#define MAX_N 100000
vector<pair<long long ,long long>> line;
int n, m;

bool is_possible(long long num){
    int cnt = 0;
    long long start = 0;

    for(int i=0;i<line.size();i++){

        long long x1,x2;
        tie(x1,x2) = line[i];

        if(x2<start)    continue;

        long long tmp = (x2 - max(x1,start))/num;
        cnt += (tmp+1);
        start = max(x1,start) + (tmp+1)*num;
        if(cnt>=n)  return true;

    }
    return false;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;

    for(int i=0;i<m;i++){
        long long x1,x2;
        cin >> x1 >> x2;
        line.push_back(make_pair(x1,x2));
    }
    sort(line.begin(),line.end());

    long long left = 0, right = 1e18, ans = 0;
    while(left<=right){
        long long mid = (left+right)/2;
        if(is_possible(mid)){
            left = mid+1;
            ans = max(mid,ans);
        }
        else{
            right = mid-1;
        }
    }
    cout<<ans;
    return 0;
}
