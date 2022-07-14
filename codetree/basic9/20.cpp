#include <iostream>
#include <string>
using namespace std;
int main(){
    string arr;
    cin >> arr;
    bool is_print =false;
    for(int i=arr.length()-1;i>=0;i--){
        if(arr[i] != '0')   is_print = true;
        if(is_print)    cout<<arr[i];
    }
    return 0;
}
