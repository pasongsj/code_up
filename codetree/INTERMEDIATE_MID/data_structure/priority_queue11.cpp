#include <iostream>
#include <queue>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    priority_queue<pair<int,int>> arr;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        
        if(x == 0){
            if(arr.size()==0){
                cout<<0<<'\n';
                continue;
            }
            pair<int,int> tmp = arr.top();
            cout<<-tmp.second<<'\n';
            arr.pop();
        }
        else    arr.push(make_pair(-abs(x),-x));
    }
    return 0;
}
