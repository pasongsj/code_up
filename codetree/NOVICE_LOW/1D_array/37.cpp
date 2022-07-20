#include <iostream>
#include <climits>
using namespace std;
int main(){
    int n,min_val=1000,max_val = 1;
    for(int i=0;i<10;i++){
        cin >> n;
        if(n<min_val && n>500)  min_val = n;
        if(n>max_val && n<500)  max_val = n;
    }
    cout<< max_val<<' '<<min_val;
    return 0;
}
