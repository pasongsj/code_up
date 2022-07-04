#include <iostream>
using namespace std;
int main(){
    int a,b,result = 1;
    cin >> a >> b;
    for(int i=a;i<=b;i++)   result *= i;
    cout << result;
    return 0;
}
