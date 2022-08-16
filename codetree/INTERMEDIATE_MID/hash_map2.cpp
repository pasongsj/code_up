#include <iostream>
#include <unordered_map>

using namespace std;
int main(){
    unordered_map<int, int> d;
    int n, m, num;
    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >> num;
        if(d.find(num)!=d.end()){
            d[num] ++;
        }
        else    d[num] = 1;
    }

    for(int i=0;i<m;i++){
        cin >> num;
        if(d.find(num)!=d.end()){
            cout<<d[num]<<' ';
        }
        else    cout<<0<<' ';
    }
    return 0;
}
