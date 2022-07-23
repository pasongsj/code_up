#include <iostream>
using namespace std;

int arr[100];
int ch_arr[100];

void bomb(int n, int m){
    int com = arr[0];
    int cnt = 1;
    int index = 0;
    for(int i=1;i<n;i++){
        if(com == arr[i])   cnt ++;
        else{
            if(cnt >= m)    com = 0;
            
            for(int j=0;j<cnt;j++){
                ch_arr[index++] = com;
            }
            com = arr[i];
            cnt = 1;
        }
    }
    if(cnt >= m)    com = 0;
    for(int j=0;j<cnt;j++){
        ch_arr[index++] = com;
    }
}

int erase_zero(int n){
    int ans = 0;
    for(int i=0;i<n;i++){
        if(ch_arr[i]>0){
            arr[ans++] = ch_arr[i];
        }
        ch_arr[i] = 0;
    }
    return ans;
}

int main(){
    int n,m,before_len=0;
    cin >> n >> m;
    for(int i=0;i<n;i++)    cin >> arr[i];
    bomb(n,m);
    n = erase_zero(n);

    while(true){
        bomb(n,m);
        n = erase_zero(n);
        if(before_len == n) break;
        before_len = n;
    }
    cout<<n<<endl;
    for(int i=0;i<n;i++)    cout<<arr[i]<<endl;
    return 0;
}
