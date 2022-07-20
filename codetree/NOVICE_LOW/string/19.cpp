#include <iostream>
#include <string>

using namespace std;
int main(){
    string arr;
    int sum = 0;
    cin >> arr;
    for(int i=0;i<arr.length();i++){
        if('0'< arr[i] && arr[i]<='9'){
            sum += arr[i]-'0';
        }
    }
    cout<<sum;
    return 0;
}
