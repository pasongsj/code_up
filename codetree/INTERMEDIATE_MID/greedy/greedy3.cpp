#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;


vector<tuple<double,int,int>> jewel;
int main(){
    int n,m;
    cin >> n >> m;
    for(int i=0;i<n;i++){
        int w,v;
        cin >> w >> v;
        jewel.push_back(make_tuple(-(double)v/w,w,v));
    }
    sort(jewel.begin(),jewel.end());

    double ans=0;
    for(int i=0;i<n;i++){
        int w,v;
        tie(ignore,w,v) = jewel[i];
        if(m-w<0){
            ans+=((double)m/w) * v;
            break;
        }
        m-= w;
        ans += v;
    }
    cout<<fixed;
    cout.precision(3);
    cout<<ans;
    return 0;
}
