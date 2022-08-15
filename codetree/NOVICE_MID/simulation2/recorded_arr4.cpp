#include <iostream>
#include <map>
using namespace std;
#define MAX_NM 10000001
int main(){
    int n,m;
    cin >> n >> m;
    int arrA[MAX_NM] = {0},arrB[MAX_NM] = {0};
    int mov,pos_a = 1, pos_b = 1;
    char dir;
    map<char,int> d = {{'L',-1},{'R',1}};
    for(int i=0;i<n;i++){
        cin >> mov >> dir;
        for(int j=0;j<mov;j++){
            arrA[pos_a] = arrA[pos_a-1]+d[dir];
            pos_a++;
        }
    }
    for(int i=0;i<m;i++){
        cin >> mov >> dir;
        for(int j=0;j<mov;j++){
            arrB[pos_b] = arrB[pos_b-1]+d[dir];
            pos_b++;
        }
    }
    int ans = 0;
    int cur_a,cur_b,last_a = arrA[0], last_b = arrB[0];
    for(int i=1;i<(pos_a>pos_b?pos_a:pos_b);i++){
        if(i<pos_a) cur_a = arrA[i];
        if(i<pos_b) cur_b = arrB[i];
        
        if(last_a!=last_b && cur_a==cur_b)  ans++;
        
        last_a = cur_a;
        last_b = cur_b;

    }
    cout<<ans;
    return 0;

}
