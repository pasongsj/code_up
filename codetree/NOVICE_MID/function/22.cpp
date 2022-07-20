#include <iostream>
using namespace std;

void abs_f(int &a){
    if(a<0) a *= -1;
}

int main(){
    int n, m;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> m;
        abs_f(m);
        cout<<m<<' ';
    }
    return 0;   
}
