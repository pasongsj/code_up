#include <iostream>
#include <vector>

using namespace std;

int n,m,k;//n 턴 m 판 길이 k 말 수
int turn[12];//2424
int coin[4];
vector<int> num;
int ans;
int cal(){
    int cnt = 0;
    for(int i=0;i<k;i++){
        if(coin[i]>=m)  cnt++;
    }
    return cnt;
}

void get_mov(int cur_num){//m은 자리 수

    if(cur_num == n){
        ans = max(ans,cal());
        return;
    }
    for(int i=0;i<k;i++){
        coin[i] += turn[cur_num];
        get_mov(cur_num+1);
        coin[i] -= turn[cur_num];
    }
    
}

int main(){
    
    cin >> n >> m >> k;

    ans = 0;

    for(int i=0;i<n;i++)    cin >> turn[i];//2424
    for(int i=0;i<k;i++)    coin[i] = 1;

    get_mov(0);

    cout<<ans;
    return 0;
}
