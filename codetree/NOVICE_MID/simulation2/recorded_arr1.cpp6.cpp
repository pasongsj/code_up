#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    vector<int> arrN = {0}, arrM = {0};
    while(n--){
        int v,t;
        cin >> v >> t;
        while(t--){
            arrN.push_back(arrN.back()+v);
        }
    }
    while(m--){
        int v,t;
        cin >> v >> t;
        while(t--){
            arrM.push_back(arrM.back()+v);
        }
    }
    int ans = 0, before = 3;
    int now;
    for(int i=1;i<arrN.size();i++){
        if(arrN[i]>arrM[i]) now = 1;
        else if(arrN[i]< arrM[i])   now = 2;
        else now = 3;
        if(before == now)   continue;
        else ans++;
        before = now;
    }
    cout<< ans;
    return 0;
}
