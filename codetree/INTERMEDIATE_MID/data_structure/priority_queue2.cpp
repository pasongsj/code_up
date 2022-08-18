#include <iostream>
#include <queue>

using namespace std;
int main(){
    int n,m,tmp;
    cin >> n >> m;
    priority_queue<int> arr;
    for(int i=0;i<n;i++){
        cin >> tmp;
        arr.push(tmp);
    }
    for(int j=0;j<m;j++){
        arr.push(arr.top()-1);
        arr.pop();
    }
    cout<<arr.top();
    return 0;
}
