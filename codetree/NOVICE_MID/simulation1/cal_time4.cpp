#include <iostream>
#include <string>
using namespace std;

int cal_days(int m, int d){
    int sum = 0;
    int num_of_days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    for(int i=0;i<m-1;i++){
        sum += num_of_days[i];
    }
    return sum + d;
}


int main(){
    string days[7] = {"Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun"};
    int m1,m2,d1,d2;
    cin >> m1 >> d1 >> m2 >> d2;
    int res = cal_days(m2,d2)-cal_days(m1,d1);
    if(res<0)   res = res%7+7;
    else    res %= 7;
    cout<<days[res];
    return 0;

}
