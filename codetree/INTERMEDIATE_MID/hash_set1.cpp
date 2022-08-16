#include <iostream>
#include <unordered_set>
#include <string>

using namespace std;

int main(){
    unordered_set<int> d;
    int n, k;
    cin >> n;
    for(int i=0;i<n;i++){
        string s;
        cin >> s >> k;
        if(s == "add")  d.insert(k);
        else if(s == "find"){
            if(d.find(k) != d.end())    cout<<"true"<<endl;
            else    cout<<"false"<<endl;
        }
        else    d.erase(k);
    }
    return 0;
}
