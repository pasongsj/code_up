#include <iostream>
using namespace std;
int main(){
    long long n,n_can,m_can,i,j,cnt = 0;
    cin >> n;
    long long m[n];
    for(i=0;i<n;i++)    cin >>m[i];
    cin >> n_can >> m_can;

    for(j=0;j<n;j++){
        if(m[j]-n_can<=0)   cnt ++;
        else if((m[j]-n_can)%m_can==0)  cnt += ((m[j]-n_can)/m_can + 1);
        else    cnt += ((m[j]-n_can)/m_can + 2);
    }
    cout<<cnt;
    return 0;
}
