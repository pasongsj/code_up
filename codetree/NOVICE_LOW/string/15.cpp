#include <iostream>
#include <string>
using namespace std;
int main(){
    string arr[10];
    char a;
    int cnt = 0;
    for(int i=0;i<10;i++)   cin>>arr[i];
    cin>>a;

    for(int j=0;j<10;j++){
        if(a==arr[j][arr[j].length()-1]){
            cout<<arr[j]<<endl;
            cnt ++;
        }
    }
    if(cnt==0)  cout<<"None";
    return 0;
}
