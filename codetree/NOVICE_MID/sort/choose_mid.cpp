#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> arr;
    for(int i=1;i<=n;i++){
        int tmp;
        cin >> tmp;
        arr.push_back(tmp);
        if(i%2 == 1){
            sort(arr.begin(),arr.end());
            cout<<arr[i/2]<<' ';
        }
    }
    return 0;
}
