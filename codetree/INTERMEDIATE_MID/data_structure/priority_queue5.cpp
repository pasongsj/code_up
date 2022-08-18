#include <iostream>
#include <queue>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    priority_queue<int> arr;
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        int tmp;
        cin >> tmp;
        arr.push(tmp);
        if(tmp == 0){
            cout<<arr.top()<<'\n';
            arr.pop();
        }
    }
    return 0;
}
