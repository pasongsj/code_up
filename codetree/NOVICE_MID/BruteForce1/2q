#include <iostream>
using namespace std;
#define MAX_N 100
int main(){
    int n, ans = 0;
    cin >> n;
    int arr[MAX_N] = {0};
    for(int i=0;i<n;i++)    cin>>arr[i];

    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int avg = 0;
            for(int k=i;k<=j;k++)   avg += arr[k];

            if(avg%(j-i+1)!=0)  continue;
            
            avg /= (j-i+1);

            for(int k=i;k<=j;k++){
                if(avg == arr[k]){
                    ans++;
                    break;
                }
            }
        }
    }
    cout<< ans;
    return 0;
}
