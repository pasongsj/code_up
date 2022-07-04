#include <iostream>
using namespace std;
int main(){
    int n;
    while(true){
        cin >> n;
        if(n<25)    cout<<"Higher\n";
        else if(n>25)    cout<<"Lower\n";
        else{
            cout<<"Good";
            break;
        }
    }
    return 0;
}
