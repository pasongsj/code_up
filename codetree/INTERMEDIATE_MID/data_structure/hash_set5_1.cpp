#include <iostream>
#include <unordered_set>

using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m,same = 0;
    cin >> n >> m;
    unordered_set<int> arrA;
    unordered_set<int> arrB;

    for(int i=0;i<n;i++){
        int tmp;
        cin >> tmp;
        arrA.insert(tmp);
    }
    for(int i=0;i<m;i++){
        int tmp;
        cin >> tmp;
        arrB.insert(tmp);
        if(arrA.find(tmp)!=arrA.end())  same++;
    }
    cout<<arrA.size()+arrB.size()-same*2;

    return 0;
}

