#include <iostream>
using namespace std;
int main(){
    double score,sum_val = 0;
    for(int i=0;i<8;i++){
        cin>>score;
        sum_val += score;
    }
    cout<<fixed;
    cout.precision(1);
    cout<<sum_val/8;
    return 0;
}
