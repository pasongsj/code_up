#include <iostream>
#include <string>
using namespace std;
#define MAX_N 1000

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, ans = 0;
    cin >> n;
    string start, goal;
    cin >> start >> goal;
    bool is_same = true;
    for(int i=0;i<n;i++){
        if(is_same && start[i] != goal[i]){
            is_same = false;
            ans++;
        }
        else if(start[i] == goal[i]){
            is_same = true;
        }
    }
    cout<<ans;
    return 0;

}
