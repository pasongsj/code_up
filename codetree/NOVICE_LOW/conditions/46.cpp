#include<iostream> 
using namespace std;
int main(){
    int t1,t2,t3;
    char e1,e2,e3;
    cin >> e1 >> t1 >> e2 >> t2 >> e3 >> t3;
    if(e1 == 'Y' && t1 >= 37){
        if(e2 == 'Y'&& t2 >= 37 || e3 == 'Y' && t3 >= 37)    cout<<'E';
        else    cout << 'N';
    }
    else{
        if(e2 == 'Y'&& t2 >= 37 && e3 == 'Y' && t3 >= 37)    cout<<'E';
        else    cout << 'N';
    }
    return 0;
}
