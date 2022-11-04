#include <iostream>
#include <unordered_map>
using namespace std;

int main(){
    unordered_map<int,int> arr;
    int now = 0;
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        int t;
        char d;
        cin >> t >> d;
        for(int j=0;j<t;j++){
            if(d == 'R')    arr[now+j] = 2;    
            else    arr[now-j] = 1;
        }
        if(d == 'R')    now += t-1;
        else    now -= t-1;
    }
    int w = 0,b = 0;
    for(auto it = arr.begin();it!=arr.end();it++){
        if(it->second == 2) b++;
        else    w++;
    }
    cout<< w<<' '<<b;
    return 0;
}
