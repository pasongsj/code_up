#include <iostream>
#include <unordered_set>

using namespace std;
int main(){
    int n,m,tmp;
    cin >> n;
    unordered_set<int> d;
    for(int i=0;i<n;i++){
        cin >> tmp;
        d.insert(tmp);
    }
    cin >> m;
    for(int i=0;i<m;i++){
        cin >> tmp;
        if(d.find(tmp) == d.end())  cout<<0<<' ';
        else    cout<<1<<' ';
    }
    return 0;
    
}
