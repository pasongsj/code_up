#include <iostream>
#include <queue>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    priority_queue<long long int>arr;
    
    for(int i=0;i<n;i++){
        long long int tmp;
        cin >> tmp;
        arr.push(tmp);
    }
    while(true){
        if(arr.empty()){
            cout<<-1;
            return 0;
        }
        else if(arr.size()==1){
            cout<<arr.top();
            return 0;
        }
        long long int last,before;
        last = arr.top();
        arr.pop();
        before = arr.top();
        arr.pop();
        if(last-before>0)   arr.push(last-before);
    }
    return 0;
}
