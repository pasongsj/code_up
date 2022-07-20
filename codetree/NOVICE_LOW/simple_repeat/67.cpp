#include <iostream>
using namespace std;
int main(){
    int row,col;
    char a;
    while(1){
        cin >> row >> col >> a;
        cout<<row*col<<endl;
        if(a == 'C')    break;
    }
    return 0;
}
