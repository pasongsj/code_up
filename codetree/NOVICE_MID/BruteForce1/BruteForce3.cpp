#include <iostream>
using namespace std;

int main(){
    int n,a,b,c,x,y,z;
    int ans,tmpx = 0, tmpy = 0, tmpz = 0;
    cin >> n;
    cin >> a >> b >> c >> x >> y >> z;
    if(n>=5)    ans = 250;
    else    ans = n*n*n*2;
    for(int i=1;i<=n;i++){
        if((abs(i-a)<=2 || abs(i-a)>=n-2) && (abs(i-x)<=2 || abs(i-x)>=n-2))    tmpx++;
        if((abs(i-b)<=2 || abs(i-b)>=n-2) && (abs(i-y)<=2 || abs(i-y)>=n-2))    tmpy++;
        if((abs(i-c)<=2 || abs(i-c)>=n-2) && (abs(i-z)<=2 || abs(i-z)>=n-2))    tmpz++;
        
    }
    cout<<ans - tmpx*tmpy*tmpz;
    return 0;
}

