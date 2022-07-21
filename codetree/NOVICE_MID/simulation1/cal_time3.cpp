#include <iostream>
using namespace std;

int cal_min(int d, int h,int m){
    return (d * 24 + h) * 60 + m;
}
int main(){
    int a,b,c;
    cin>>a>>b>>c;
    int res = cal_min(a,b,c) - cal_min(11,11,11);
    if(res>=0)   cout<<res;
    else cout<<-1;
    return 0;
}
