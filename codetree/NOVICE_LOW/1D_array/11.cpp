#include <iostream>
using namespace std;
int main(){
    int n[10];
    int sum_odd=0,sum_even=0;
    for(int i=0;i<10;i++){
        cin>>n[i];
    }
    for(int j=0;j<10;j++){
        if(j%2==0)  sum_odd += n[j];
        else    sum_even += n[j];
    }
    cout<<abs(sum_even-sum_odd);
    return 0;
}
