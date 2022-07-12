#include <iostream>
#include <climits>
using namespace std;
int main(){
    int n,max_val = INT_MIN, min_val = INT_MAX;
    for(int i=0;i<100;i++){
        cin>>n;
        if(n==999||n==-999) break;
        if(n>max_val)   max_val = n;
        if(n<min_val)   min_val = n;
    }
    cout<<max_val<<' '<<min_val;
    return 0;
}
