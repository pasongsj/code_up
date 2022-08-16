#include <iostream>
#include <map>

using namespace std;
int main(){
    map<int,int> d;
    int n,k,v;
    cin >> n;
    for(int i=0;i<n;i++){
        string s;
        cin >> s ;
        if(s == "add"){
            cin >> k >> v;
            d[k] = v;
        }
        else if(s == "remove"){
            cin >> k;
            d.erase(k);
        }
        else if(s == "find"){
            cin >> k;
            if(d.find(k) != d.end()){
                cout<<d[k]<<endl;
            }
            else    cout<<"None"<<endl;
        }
        else{
            if(d.empty())  cout<<"None"<<endl;
            else{
                map<int, int>::iterator j;
                for(j=d.begin();j!=d.end();j++) cout<<(j->second)<<' ';
                cout<<endl;
            }
        }
    }
    return 0;
}
