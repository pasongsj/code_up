#include <iostream>
using namespace std;

int a[100],b[100];

bool f(int n, int m) {
    bool is_same = false;  
    for(int i=0;i<n;i++){
        if(a[i]==b[0]){
            is_same = true;
            for(int j=1;j<m;j++){
                if(a[i+j] != b[j]){
                    is_same = false;
                    break;
                }
            }
        }
        if(is_same) return is_same;
    }
    return is_same;
}
int main() {  
    int n1, n2;
    cin >> n1 >> n2;
    for(int i=0;i<n1;i++)   cin >> a[i];
    for(int j=0;j<n2;j++)   cin >> b[j];
    if(f(n1,n2))    cout<<"Yes";
    else    cout<<"No";
    return 0;
}
