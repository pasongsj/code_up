#include <iostream>
#include <climits>
using namespace std;
int main(){
    int a, n, max_val,is_val = 0;
    cin>>n;
    int m[1000] = {0, };
    for (int i=0;i<n;i++){
        cin>>a;
        m[a-1]++;
    }
    for(int j=999;j>=0;j--){
        if(m[j]==1){
            cout<<j+1;
            is_val =1;
            break;
        }
    }
    if(is_val == 0) cout<<-1;
    return 0;
}
