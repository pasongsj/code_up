#include <iostream>
#include <set>
using namespace std;
int main(){
    int t,k,n;
    char cal;
    cin >> t;
    for(int i=0;i<t;i++){
        cin >> k;
        set<int> d;
        for(int j=0;j<k;j++){
            cin >> cal >> n;
            if(cal == 'I')  d.insert(n);
            else{
                if(!d.empty()){
                    if(n == 1)  d.erase(*d.rbegin());
                    else    d.erase(*d.begin());
                }
            }
        }
        if(d.empty())   cout<<"EMPTY"<<endl;
        else    cout<<*d.rbegin()<<' '<<*d.begin()<<endl;
    }
    return 0;
}
