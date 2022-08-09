#include <iostream>
using namespace std;
#define MAX_N 20

bool is_carry(int a, int b, int c){
    while(a!=0 || b!=0 || c!=0){
        if((a%10+b%10+c%10) >= 10)  return false;
        a /= 10;
        b /= 10;
        c /= 10;
    }
    return true;
}
int main(){
    int n,ans = -1;
    cin >> n;
    int arr[MAX_N];
    for(int i=0;i<n;i++)    cin>>arr[i];
    
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                if(is_carry(arr[i],arr[j],arr[k])){
                    ans = max(ans,arr[i]+arr[j]+arr[k]);
                }
            }
        }
    }
    cout<<ans;
    return 0;
}
