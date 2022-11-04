#include <iostream>
#include <map>
#include <vector>
using namespace std;
bool is_gray(vector<char> paint){
    int w = 0,b = 0;
    for(int i=0;i<paint.size();i++){
        if(paint[i] == 'W') w++;
        else   b++;
    }
    return (w>=2 && b>=2);
}

int main(){
    int n;
    cin >> n;
    map<int,vector<char>> arr;
    int min_v = 0, max_v = 0, now = 0;

    for(int i=0;i<n;i++){
        int t;
        char d;
        cin >> t >> d;
        for(int j=0;j<t;j++){
            if(d == 'R') arr[now+j].push_back('B');
            else    arr[now-j].push_back('W');
        }
        if(d == 'R')    now += (t-1);
        else now-=(t-1);
    }
    int w = 0, b = 0,g = 0;
    for(auto it = arr.begin();it != arr.end(); it++){
        if(is_gray(it->second)) g++;
        else if(it->second.back() == 'W')   w++;
        else    b++;
    }
    cout<<w<<' '<<b<<' '<<g;
    return 0;
}
