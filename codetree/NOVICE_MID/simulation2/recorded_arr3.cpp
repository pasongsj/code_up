#include <iostream>
using namespace std;
#define MAX_NUM 1000000

int main(){
    int n,m;
    int arrA[MAX_NUM] = {0},arrB[MAX_NUM] = {0};
    cin >> n >> m;
    int v,t;
    int pos_a = 1,pos_b = 1;
    for(int i=0;i<n;i++){
        cin >> v >> t;
        for(int j=0;j<t;j++){
            arrA[pos_a] = arrA[pos_a-1]+v;
            pos_a++;
        }
    }
    for(int i=0;i<m;i++){
        cin >> v >> t;
        for(int j=0;j<t;j++){
            arrB[pos_b] = arrB[pos_b-1]+v;
            pos_b++;
        }
    }
    int ans = 0,diff = arrA[1]- arrB[1];
    for(int i=2;i<pos_a;i++){
        int tmp = arrA[i]-arrB[i];
        if(tmp * diff < 0){
            ans ++;
        }
        if(tmp<0)   diff = -1;
        else if(tmp>0)    diff = 1;
   }
    cout<<ans;
    return 0;

}
