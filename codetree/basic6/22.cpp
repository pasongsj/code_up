#include <iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    for(int i=1; i<=n; i++){
        if(i==1)    for(int j=0;j<n;j++)    cout<<"* ";
        else{
            cout<<"  ";
            for(int k=0; k<(i-1)/2; k++)    cout<<"    ";
            for(int l=0; l<=n/2 - (i+1)/2; l++)  cout<<"*   ";
        }
        cout<<endl;
    }
    return 0;
}
