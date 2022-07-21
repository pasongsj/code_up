#include <iostream>
#include <algorithm>
using namespace std;

#define MAX_N 100
#define MAX_ARR 2000
#define OFFSET 1000

int main(){
    int n, x, pos = OFFSET,max_pos=0,min_pos=MAX_ARR;
    char dir;
    cin >> n;
    int arr[MAX_ARR] ={};
    for(int i=0;i<n;i++){
        cin >> x >> dir;
        for(int j=0;j<x;j++){
            if(dir == 'L') arr[--pos]++; 
            else    arr[pos++]++;
        }
        if(max_pos<pos) max_pos = pos;
        if(min_pos>pos) min_pos = pos;
    }

    int ans = 0;
    for(int i=min_pos;i<=max_pos;i++){
        if(arr[i]>=2)   ans++;
    }
    cout<<ans;
    return 0;
}
    
