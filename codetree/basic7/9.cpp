#include <iostream>
using namespace std;
int main(){
    int n[100];
    int index=0;
    cin >> n[index];
    while(n[index] != 0){
        index++;
        cin>>n[index];
    }
    cout<< n[index-1]+n[index-2]+n[index-3];
    return 0;
}
