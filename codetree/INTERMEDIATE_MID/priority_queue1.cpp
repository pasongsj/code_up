#include<iostream>
#include <queue>
using namespace std;
int main(){
    priority_queue<int> pq;
    int n,k;
    cin >> n;
    for(int i=0;i<n;i++){
        string s;
        cin >> s;
        if(s == "push"){
            cin >> k;
            pq.push(k);
        }
        else if(s == "pop"){
            cout<<pq.top()<<endl;
            pq.pop();
        }
        else if(s == "size"){
            cout<<pq.size()<<endl;
        }
        else if(s == "empty"){
            if(pq.empty())  cout<<1<<endl;
            else    cout<<0<<endl;
        }
        else    cout<<pq.top()<<endl;
    }

    return 0;
}
