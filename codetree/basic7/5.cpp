#include <iostream>
using namespace std;
int main(){
    int n,a,b,c,d,cnt = 0;
    cin >> n;
    double m[n];
    for(int i=0;i<n;i++){
        cin >> a >> b >> c >> d;
        m[i] = (double)(a+b+c+d)/4;
    }
    for(int j=0;j<n;j++){
        if(m[j]>=60){
            cout<<"pass"<<endl;
            cnt++;
        }
        else    cout<<"fail"<<endl;
    }
    cout<<cnt;
    return 0;
}
