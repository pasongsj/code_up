#include <iostream>
using namespace std;
int main(){
    int n,result = 0;
    cin >> n;
    int m[n];
    for(int i=0;i<n;i++){
        cin >> m[i];
    }
    for(int j=0;j<n;j++){
        for(int k=j+1;k<n;k++){
            if(m[k]-m[j]>result)    result = m[k]-m[j];
        }
    }
    cout<<result;
    return 0;
}

