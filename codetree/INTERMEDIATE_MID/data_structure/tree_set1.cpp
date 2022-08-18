#include <iostream>
#include <set>

using namespace std;

int main() {
    set<int> d;
    int n,k;
    cin >> n;
    for(int i=0;i<n;i++){
        string s;
        cin >> s;
        if(s == "add"){
            cin >> k;
            d.insert(k);
        }
        else if(s == "remove"){
            cin >> k;
            d.erase(k);
        }
        else if(s == "find"){
            cin >> k;
            if(d.find(k) == d.end())    cout<<"false"<<endl;
            else    cout<<"true"<<endl;
        }
        else if(s == "lower_bound"){
            cin >> k;
            if(d.lower_bound(k)==d.end())  cout<<"None"<<endl;
            else    cout<<*d.lower_bound(k)<<endl;
        }
        else if(s == "upper_bound"){
            cin >> k;
            if(d.upper_bound(k)==d.end())  cout<<"None"<<endl;
            else    cout<<*d.upper_bound(k)<<endl;
        }
        else if(s == "largest"){
            if(d.empty())   cout<<"None"<<endl;
            else    cout<<*d.rbegin()<<endl;
        }
        else{//s == smallest{}
            if(d.empty())   cout<<"None"<<endl;
            else    cout<<*d.begin()<<endl;
        }
    }
    return 0;
}

