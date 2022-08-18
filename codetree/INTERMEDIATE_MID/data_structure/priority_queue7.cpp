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
        arr.push(-tmp);
        if(arr.size()<3)    cout<<-1<<'\n';
        else{
            long long int x,y,z;
            x=arr.top(),arr.pop();
            y=arr.top(),arr.pop();
            z=arr.top(),arr.pop();
            cout<<-x*y*z<<'\n';
            arr.push(x),arr.push(y),arr.push(z);
        }
    } 
    return 0;
}
