#include <iostream>
using namespace std;
int main(){
    int n, cnt=1;
    cin >> n;
    for(int i=n;i>0;i--){
        for(int j=n;j>0;j--){
            if(j>i) cout << "  ";
            else{
                cout << cnt << ' ';
                cnt++;

            }
            if(cnt>9)   cnt = 1;
        }
        cout<<endl;
    }
    return 0;
}
