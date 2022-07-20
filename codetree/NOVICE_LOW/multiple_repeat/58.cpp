#include <iostream>
using namespace std;
int main(){
    int start, end, cnt = 0, num;
    cin >> start >> end;
    for(int i=start; i<=end; i++){
        num = 1;
        for(int j=2;j<i;j++){
            if(i%j==0)  num += j;
        }
        if(i == num)    cnt++; 
    }
    cout<<cnt;
    return 0;
}
