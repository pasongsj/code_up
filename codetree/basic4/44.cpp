#include<iostream>
using namespace std;
int main(){
    int y;
    cin >> y;
    if(y==2)    cout << 28;
    else if(y < 8 && y % 2 == 1 || y >= 8 && y % 2 ==0)   cout<< 31;
    else    cout<<30;
    return 0;
}

