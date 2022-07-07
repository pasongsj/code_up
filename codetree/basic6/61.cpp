#include <iostream>
using namespace std;
int main(){
    int n,a,b,cnt;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a >> b;
        cnt = 0;
        for(int j=a;j<=b;j++){
            if(j%2==0)  cnt +=j;
        }
        cout<<cnt<<endl;
    }
    return 0;
}
