
#include <iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    for (int i=0;i<n;i++){
        if(i==0)    for(int j=1;j<n;j++)    cout<<"* ";
        else{
            for(int k=0;k<i;k++)    cout<<"* ";
            for(int l=0;l<(n-i-1);l++)  cout<<"  ";
        }
        cout<<"* "<<endl;
    }
    return 0;
}
