#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

bool cmp(tuple<int,int,int> a, tuple<int,int,int> b){
    int h1,w1,i1, h2,w2,i2;
    tie(h1,w1,i1) = a;
    tie(h2,w2,i2) = b;
    if(h1 == h2)    return w1>w2;
    return h1<h2;
}
int main(){
    int n;
    cin >> n;
    vector<tuple<int,int,int>> arr;
    for(int i=1;i<=n;i++){
        int h, w;
        cin >> h >> w;
        arr.push_back(make_tuple(h,w,i));
    }
    sort(arr.begin(),arr.end(),cmp);

    for(int i=0;i<arr.size();i++){
        int h, w, j;
        tie(h,w,j) = arr[i];
        cout<<h<<' '<<w<<' '<<j<<'\n';
    }
    return 0;
}
