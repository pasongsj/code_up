#include <iostream>
using namespace std;
#define MAX_N 1000

char arr[MAX_N];
char goal[MAX_N];
int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, ans = 0;
    cin >> n;
    for(int i=0;i<n;i++)    cin >> arr[i];
    for(int i=0;i<n;i++)    cin >> goal[i];
    
    bool is_flip = false;
    for(int i=n-1;i>=0;i--){
        if(arr[i] == goal[i]){
            if(is_flip){
                ans++;
                is_flip = false;
            }
        }
        else{//arr[i] != goal[i]
            if(!is_flip){ // falsse
                ans++;
                is_flip = true;
            }
        }
    }
    cout<<ans;
}
