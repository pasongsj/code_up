#include <iostream>
#include <set>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,k;
    cin >> n >> k;

    set<int>arr;
    for(int i=0;i<n;i++){
        long long tmp;
        cin >> tmp;
        arr.insert(tmp);
    }
    set<int>::iterator ans = arr.end();
    for(int i=0;i<k;i++)    cout<<*(--ans)<<' ';
    
    return 0;
}
