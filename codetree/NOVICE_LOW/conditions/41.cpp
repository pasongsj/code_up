#include<iostream>
using namespace std;
int main(){
    int jen, old;
    cin >> jen >> old;
    if(jen == 0){
        if(old > 18)    cout << "MAN";
        else    cout << "BOY";
    }
    else{
        if(old > 18)    cout << "WOMAN";
        else    cout << "GIRL";
    }
    return 0;
}
