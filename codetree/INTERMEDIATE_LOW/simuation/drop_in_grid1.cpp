#include <iostream>
#include <vector>
using namespace std;

vector<int> d;

int main(){
    int n; cin >> n;
    for(int i=1;i<=n;i++){
        int a; cin >> a;
        d.push_back(a);
    }

    int s_1, e_1; cin >> s_1 >> e_1;
    d.erase(d.begin()+s_1-1,d.begin()+e_1);
    int s_2, e_2; cin >> s_2 >> e_2;
    d.erase(d.begin()+s_2-1,d.begin()+e_2);
    
    cout << d.size() << '\n';
    for(int i=0;i<d.size();i++) cout << d[i] << '\n';
}
