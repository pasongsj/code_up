#include <iostream>
#include <algorithm>
using namespace std;

int n,ans;
int arr[10];

void Choose(int cur_pos,int cnt){
    if(cur_pos >= n-1){
        if(cnt == (n-2)/4+1){//과정을 줄이기 위해
            cout<<cnt;
            exit(0);
        }
        if(ans != -1)   ans = min(ans,cnt);
        else    ans = cnt;
        return;
    }
    if(arr[cur_pos]==0) return;

    for(int i=arr[cur_pos];i>=1;i--){
        Choose(cur_pos+i,cnt+1);
    }

}

int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    ans = -1;
    Choose(0,0);
    cout<<ans;
    return 0;
}
