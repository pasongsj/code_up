#include <iostream>
#include <queue>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    priority_queue<int> arr;
    for(int i=0;i<n;i++){
        int tmp;
        cin >> tmp;
        if(tmp == 0){
            if(!arr.empty()){
                tmp = -arr.top();
                arr.pop();
            }
            cout<<tmp<<'\n';
        }
        else    arr.push(-tmp);
    }
    return 0;
}
