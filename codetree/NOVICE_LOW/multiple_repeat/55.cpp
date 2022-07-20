#include <iostream>
using namespace std;
int main(){
    int n;
    char a = 65;
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(j<i) cout<<"  ";
            else{
                cout<<a<<' ';
                a++;
                if(a == 91) a=65;
            }
        }
        cout<<endl;
    }
    return 0;
}
