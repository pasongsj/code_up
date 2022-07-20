#include <iostream>
using namespace std;
void swap(int *a,int *b){
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}
int main(){
    int n,m;
    cin >> n >> m;
    swap(&n,&m);
    cout<<n<<' '<<m;
    return 0;
}
