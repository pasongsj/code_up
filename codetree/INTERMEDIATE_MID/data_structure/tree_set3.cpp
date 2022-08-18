#include <iostream>
#include <set>
using namespace std;
int main(){
    set<int> d;
    int n,m,tmp;
    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >> tmp;
        d.insert(tmp);
    }
    for(int j=0;j<m;j++){
        cin >> tmp;
        if(d.lower_bound(tmp) == d.end())   cout<<-1<<endl;
        else    cout<< *d.lower_bound(tmp)<<endl;
    }
    return 0;

}
