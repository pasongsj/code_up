#include<iostream>
using namespace std;
int main(){
    int m1,e1,m2,e2;
    cin >> m1 >> e1 >> m2 >> e2;
    cout << (m1 == m2 ? (e1 > e2 ? "A" : "B") : (m1 > m2 ? "A" : "B"));
    return 0;
}
