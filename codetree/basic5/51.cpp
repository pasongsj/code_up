#include <iostream>
using namespace std;
int main(){
    int a,b,result=1;
    cin >> a >> b;
    for(int i=0;i<b;i++)   result*=a;
    cout << result;
    return 0;
} 
