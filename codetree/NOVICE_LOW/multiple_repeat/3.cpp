#include <iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    for (int sq=0; sq<2; sq++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)    cout<<"*";
            cout<<"\n";
        }
        cout<<"\n";
    }
    return 0;
}
