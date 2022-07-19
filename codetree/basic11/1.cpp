#include <iostream>
using namespace std;

void PrintStr(int n){
    if(n == 0)  return;
    PrintStr(n-1);
    cout<<"HelloWorld"<<endl;

}

int main(){
    int a;
    cin >> a;
    PrintStr(a);
    return 0;
}
