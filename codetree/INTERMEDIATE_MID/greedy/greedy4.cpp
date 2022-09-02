#include <iostream>
#include <queue>
using namespace std;


int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n,ans = 0;
    cin >> n;
    priority_queue<int> arr;
    for(int i=1;i<=n;i++){
        int tmp;
        cin >> tmp;
        arr.push(-tmp);
    }
    while(arr.size()>1){
        int x,y;
        x = arr.top(); arr.pop();
        y = arr.top(); arr.pop();
        arr.push(x+y);
        ans+=(x+y);
    }
    cout<<-ans;
    return 0;

}
