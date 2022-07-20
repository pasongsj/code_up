#include <iostream>
using namespace std;
int main(){
    int a,b,result = 0;
    cin >> a >> b;
    int n[b] = {0,};
    while(a >1 ){
        n[a%b]++;
        a /= b;
    }
    for(int i=0;i<b;i++){
        result += n[i]*n[i];
    }
    cout<<result;
    return 0;
}
