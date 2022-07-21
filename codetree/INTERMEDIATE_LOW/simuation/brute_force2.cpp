#include <iostream>
using namespace std;

int arr[100][100];

int is_happy(int n,int m){
    if(n == 1)  return 2;
    int com1,com2,cnt1,cnt2,ans = 0;
    int max_cnt1,max_cnt2;
    for(int i=0;i<n;i++){
        com1 = arr[i][0];
        com2 = arr[0][i];
        cnt1 = 1;
        cnt2 = 1;
        max_cnt1 = 0;
        max_cnt2 = 0;
        for(int j=1;j<n;j++){
            if(com1 == arr[i][j])    cnt1++;
            else{
                com1 = arr[i][j];
                cnt1 = 1;
            }
            if(com2 == arr[j][i])   cnt2++;
            else{
                com2 = arr[j][i];
                cnt2 = 1;
            }
            if(max_cnt1 < cnt1) max_cnt1 = cnt1;
            if(max_cnt2 < cnt2) max_cnt2 = cnt2;
        }
        if(max_cnt1 >= m)   ans++;
        if(max_cnt2 >= m)   ans++;
    }
    return ans;
}


int main(){
    int n,m;
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)    cin>>arr[i][j];
    }
    cout<< is_happy(n,m);
    return 0;
}
