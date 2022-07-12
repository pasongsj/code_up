#include <iostream>
#include <climits>
using namespace std;
int main(){
    int a,max_val = INT_MIN;
    for(int i=0;i<10;i++){
        cin >> a;
        if(a > max_val)   max_val = a;
    }
    cout<<max_val;
    return 0;
}
