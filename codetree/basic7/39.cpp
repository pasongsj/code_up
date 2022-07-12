#include <iostream>
using namespace std;
int main(){
    int n,result;
    cin >> n;
    int m[n];
    for(int i=0;i<n;i++){
        cin >> m[i];
    }
    result = abs(m[0]-m[1]);
    for(int j=0;j<n;j++){
        for(int k=j+1;k<n;k++){
            if(abs(m[k]-m[j])<result)    result = abs(m[k]-m[j]);
        }
    }
    cout<<result;
    return 0;
}
