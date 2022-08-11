#include <iostream>
using namespace std;

#define MAX_POS 10001

int main(){
    int n, k, tmp_pos, ans = 0;
    cin >> n >> k;
    char arr[MAX_POS] = {0};
    char tmp_char;

    for(int i=0;i<n;i++){
        cin >> tmp_pos >> tmp_char;
        arr[tmp_pos] = tmp_char;
    }

    for(int i=1;i<=MAX_POS-k+1;i++){
        int tmp = 0;
        for(int j=i;j<=i+k;j++){
            if(arr[j]=='G') tmp += 1;
            else if(arr[j] == 'H')  tmp += 2;
        }
        ans = max(ans, tmp);
    }
    cout << ans;
    return 0;
}
