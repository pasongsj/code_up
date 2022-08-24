#include <iostream>
#include <unordered_map>
using namespace std;

#define MAX_N 1000

char arr[MAX_N + 1][MAX_N+1];
int prefix_sum[MAX_N + 1][MAX_N+1][3];

int get_sum(int c, int x1, int y1, int x2, int y2){
    return prefix_sum[x2][y2][c]-prefix_sum[x1-1][y2][c]-prefix_sum[x2][y1-1][c]+ prefix_sum[x1-1][y1-1][c];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    unordered_map<char,int> alphabet ={{'a',0},{'b',1},{'c',2}};

    int n, m, k;
    cin >> n >> m >> k;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> arr[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            for(int l=0;l<3;l++){
                prefix_sum[i][j][l] = prefix_sum[i-1][j][l]+ prefix_sum[i][j-1][l]- prefix_sum[i-1][j-1][l];
            }
            prefix_sum[i][j][alphabet[arr[i][j]]]++;
        }
    }
    for(int i=0;i<k;i++){
        int x1,y1,x2,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout<<get_sum(0,x1,y1,x2,y2)<<' '<<get_sum(1,x1,y1,x2,y2)<<' '<<get_sum(2,x1,y1,x2,y2)<<'\n';
    }

    return 0;
}


