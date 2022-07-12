#include <iostream>
#include <climits>
using namespace std;
int main(){
    int n, cnt = 1;
    long long a ,min_val = LLONG_MAX;
    cin>>n;
    for(int i=0;i<n;i++){
        cin >> a;
        if(a < min_val){
            min_val = a;
            cnt = 1;
        }
        else if(a == min_val)   cnt++;
    }

    cout<<min_val<<' ' << cnt;
    return 0;
}
