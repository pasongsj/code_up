#include <iostream>
using namespace std;
int min_num(int a,int b,int c){
    int tmp = a > b ? b : a;
    return (tmp > c ? c : tmp);
}
int main(){
    int x,y,z,result;
    cin >> x >> y >> z;
    result = min_num(x,y,z);
    cout << result;
    return 0;
}
