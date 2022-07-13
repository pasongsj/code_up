#include <iostream>
#include <string>
using namespace std;
int main(){
    string arr[10];
    int cnt = 0;
    for(int i=0;i<10;i++){
        cin>>arr[i];
        cnt += arr[i].length();
    }
    cout<<cnt;
    return 0;
}
