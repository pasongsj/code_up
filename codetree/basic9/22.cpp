#include <iostream>
#include <string>
using namespace std;
int main(){
    string arr, result;
    cin >> arr;
    for(int i=1;i<arr.length();i+=2){
        result += arr[i];
    }
    for(int i=result.length()-1;i>=0;i--) cout<<result[i];
    return 0;
}
