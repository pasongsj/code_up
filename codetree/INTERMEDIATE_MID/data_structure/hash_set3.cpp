#include <iostream>
#include <set>

using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    set<int> arr;

    for(int i=1;i<=n;i++){
        long long tmp;
        cin >> tmp;
        arr.insert(tmp);
    }
    cout<<arr.size();

    return 0;
}

