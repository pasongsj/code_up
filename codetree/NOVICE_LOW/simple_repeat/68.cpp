#include <iostream>
using namespace std;
int main(){
    int age, n = 0, sum_ages = 0;
    while(1){
        cin >> age;
        if(age<20||age>=30) break;
        sum_ages+=age;
        n++;
    }
    cout<<fixed;
    cout.precision(2);
    cout<<(double)sum_ages/n;
    return 0;
}
