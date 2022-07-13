#include <iostream>
#include <string>
using namespace std;
int main(){
    int n,sum = 0,cnt = 0;
    char a;
    cin >> n;
    string arr[n];

    for(int i=0;i<n;i++)    cin >> arr[i];

    cin >> a;

    for(int i=0;i<n;i++){
        if(arr[i][0] == a){
            sum += arr[i].length();
            cnt++;
        }
    }
    cout<<fixed;
    cout.precision(2);
    cout<<cnt<<' '<<(double)sum/cnt;
    return 0;
}
