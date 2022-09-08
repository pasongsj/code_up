#include <iostream>
#include <string>
using namespace std;
#define MAX_N 1000


char arr[MAX_N];
char goal[MAX_N];
bool isSame[MAX_N];

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, ans = 0,count = 0;
    string arr, goal;
    cin >> n >> arr >> goal;
    for(int i=0;i<n;i++){
        if(arr[i] == goal[i]){
            if(count>0) ans++;
            count = 0;
        }
        else{
            count++;
            if(count == 4){
                ans++;
                count = 0;
            }
        }
    }
    if(count > 0)   ans++;
    cout<<ans;
    return 0;
}
