#include <iostream>
using namespace std;
int main(){
    int n[10];
    int sum_val2=0,sum_val3=0, cnt=0;
    for(int i=0;i<10;i++){
        cin >> n[i];
    }
    for(int j=0;j<10;j++){
        if(j%2==1)   sum_val2 += n[j];
        if(j%3==2){
            sum_val3 += n[j];
            cnt++;
        }
    }
    cout<<fixed;
    cout.precision(1);
    cout<<sum_val2<<' '<<(double)sum_val3/cnt;
    return 0;
}
