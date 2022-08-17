#include <iostream>
#include <set>
using namespace std;
int main(){
    int n,m,tmp;
    cin >> n >> m;

    set<int> num;
    for(int i=1;i<=m;i++)   num.insert(i);
    
    for(int i=0;i<n;i++){
        cin >> tmp;
        num.erase(tmp);
        cout<<*num.rbegin()<<endl;
    }
    return 0;
}
