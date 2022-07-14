#include <iostream>
#include <string>
using namespace std;
int main(){
    int cnt = 1;
    string arr,result;
    cin >> arr;
    char word = arr[0];
    for(int i=1;i<arr.length();i++){
        if(word == arr[i])  cnt++;
        else{
            result = result + word + to_string(cnt);
            word = arr[i];
            cnt = 1;
        }
    }
    result = result + word + to_string(cnt);
    cout<<result.length()<<endl<<result;
    return 0;
}
