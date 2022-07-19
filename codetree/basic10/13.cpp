#include <iostream>
using namespace std;
int main(){
    int a, b, result;
    char cal;
    cin >> a >> cal >> b;
    if (cal == '+')  result = a+b;
    else if(cal == '-') result = a-b;
    else if(cal == '*') result = a*b;
    else if(cal == '/') result = a/b;
    else{
        cout<<"False";
        return 0;
    }
    cout<< a <<' '<<cal<<' '<<b<<" = "<<result;
    return 0;
}
