#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;
#define MAX_N 100001

string num[MAX_N];
int main(){
    int n, m;
    cin >> n >> m;

    unordered_map<string,int> arr;

    for(int i=1;i<=n;i++){
        cin >> num[i];
        arr[num[i]] = i;
    }
    for(int i=0;i<m;i++){
        string tmp;
        cin >> tmp;
        if(arr.find(tmp)!=arr.end())    cout<<arr[tmp]<<'\n';
        else    cout<<num[stoi(tmp)]<<'\n';
    }

    return 0;
}
