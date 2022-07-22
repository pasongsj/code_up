#include <iostream>
using namespace std;
int arr[100][100];
int n,m,q;

void mov_row(int row, int d){
    int tmp;
    if(d == -1){
        tmp = arr[row][m-1];
        for(int i=m-1;i>0;i--){
            arr[row][i] = arr[row][i-1];
        }
        arr[row][0] = tmp;
    }
    else{
        tmp = arr[row][0];
        for(int i=0;i<m-1;i++){
            arr[row][i] = arr[row][i+1];
        }
        arr[row][m-1] = tmp;
    }
}

void spread_upward(int row,int d){
    bool is_spread;
    for(int i=row;i>0;i--){
        is_spread = false;
        for(int j=0;j<m;j++){
            if(arr[i][j]==arr[i-1][j]){
                d *= -1;
                mov_row(i-1,d);
                is_spread = true;
                break;
            }
        }
        if(!is_spread)   break;
    }
}
void spread_down(int row,int d){
    bool is_spread;
    for(int i=row;i<n-1;i++){
        is_spread = false;
        for(int j=0;j<m;j++){
            if(arr[i][j]==arr[i+1][j]){
                is_spread = true;
                //cout<<i<<' '<< arr[i][j]<<' '<<arr[i+1][j]<<endl;
                d*=-1;
                mov_row(i+1,d);
                break;
            }
        }
        if(!is_spread)  break;
    }
}


int main(){
    int mov[100];
    char dir[100];

    cin >> n >> m >> q;
    for(int i=0;i<n;i++){//격자 입력
        for(int j=0;j<m;j++)    cin>>arr[i][j];
    }

    for(int i=0;i<q;i++){//바람 이동 입력
        cin >> mov[i] >> dir[i];
    }
    
    int dir_num;
    for(int i=0;i<q;i++){
        if(dir[i]=='L') dir_num = -1;
        else dir_num = 1;
        mov_row(mov[i]-1,dir_num);
        spread_upward(mov[i]-1,dir_num);
        spread_down(mov[i]-1,dir_num);
    }
    for(int i=0;i<n;i++){//격자 출력
        for(int j=0;j<m;j++)    cout<<arr[i][j]<<' ';
        cout<<endl;
    }
}
