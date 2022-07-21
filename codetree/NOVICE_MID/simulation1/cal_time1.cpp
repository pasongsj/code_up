#include <iostream>
using namespace std;
int main(){
    int a,b,c,d;
    int sum1,sum2;
    cin >>a>>b>>c>>d;
    sum1 = a*60+b;
    sum2 = c*60+d;
    cout<< abs(sum1-sum2);
    return 0;
}
