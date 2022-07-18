#include <iostream>
using namespace std;

//x+ 0 
//x- 1
// y+ 2 
// y- 3
//1 y+ --> x- ,x+ --> y- ,y- --> x+, x- --> y+ // 2 1, 0 3, 3 0, 1 2
//2 y+ --> x+, x+ --> y+, y- --> x-, x- --> y- // 2 0, 0 2, 3 1, 1 3

int arr[100][100];

int mov_fun(int mov, int num,int pos_x, int pos_y){
    int cnt = 0;
    while(true){
        if(arr[pos_x][pos_y] == 1){
            if(mov == 1|| mov ==3)  mov = (mov+1)%4;
            else    mov = (mov+3)%4;//2 0
        }
        else if(arr[pos_x][pos_y] == 2)    mov = (mov+2)%4;
        if((pos_x == -1||pos_x == num||pos_y == -1|| pos_y == num))  break;
        if(mov == 0)  pos_x++;
        else if(mov == 1) pos_x--;
        else if(mov == 2) pos_y++;
        else    pos_y--;
        cnt++;
    }
    return cnt;
}

int main(){
    int n,tmp,result = 0;
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)    cin>> arr[i][j];
    }
    for(int k=0;k<n;k++){
        tmp = mov_fun(0, n, 0, k);
        if(tmp>result)  result = tmp;
        tmp = mov_fun(2, n, k, 0);
        if(tmp>result)  result = tmp;
        tmp = mov_fun(1, n, n-1, k);
        if(tmp>result)  result = tmp;
        tmp = mov_fun(3, n, k, n-1);
        if(tmp>result)  result = tmp;
    }


    cout<<result+1;
    return 0;
    
}
