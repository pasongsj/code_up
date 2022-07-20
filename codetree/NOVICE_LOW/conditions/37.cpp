#include<iostream>
using namespace std;
int main(){
    int m;
    cin >> m;
    if(3<=m && m<6)    cout<<"Spring";
    else if(6<=m && m<9)    cout<<"Summer";
    else if(9<=m && m<12)    cout<<"Fall";
    else    cout<<"Winter";
    return 0;
}
