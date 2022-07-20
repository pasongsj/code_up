#include <iostream>
#include <string>
using namespace std;
int main(){
    int n, sum = 0, cnt = 0;
    cin >> n;
    string arr[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    for(int i=0;i<n;i++){
        sum += arr[i].length();
        if(arr[i][0] == 'a')    cnt ++;
    }
    cout << sum << ' ' << cnt;
    return 0;
}
