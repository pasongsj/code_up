#include <iostream>
#include <map>

using namespace std;
int main(){
    int n;
    map<string,int> d;
    cin >> n;
    for(int i=0;i<n;i++){
        string tmp;
        cin >> tmp;
        if(d.find(tmp) != d.end())  d[tmp]++;
        else    d[tmp] = 1;
    }
    cout<<fixed;
    cout.precision(4);

    map<string, int>::iterator it;
    for(it = d.begin(); it != d.end(); it++) {
        cout<< (it->first)<<' '<<(double)(it->second)/n*100<<endl;
    }
    return 0;
}


