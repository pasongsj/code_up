#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main(){
    int n,k,v;
    cin >> n;
    unordered_map<int, int> m;
    for(int i=0;i<n;i++){
        string s;
        cin >> s >> k;
        if(s == "add"){
            cin>>v;
            m[k] = v;
        }
        else if(s=="remove")    m.erase(k);
        else{
            if(m.find(k) != m.end()){
                cout<<m[k]<<endl;
            }
            else{
                cout<<"None"<<endl;
            }
        }
        
    }
    return 0;

}
