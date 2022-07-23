#include <iostream>
//#include <map>
using namespace std;

//map <char,int> dir= {{‘L',0}, {‘R’,1}, {‘U’,2}, {'D’,3}};
int arr[4][4];
int ch_arr[4][4];

void gravity(char d){
    int x=0, y=0;
    if(d=='L'){
        for(int i=0;i<4;i++){
            x = i;
            y = 0;
            for(int j=0;j<4;j++){
                if(arr[i][j]!=0)    ch_arr[x][y++] = arr[i][j];
            }
        }
    }
    else if(d=='R'){
        for(int i=0;i<4;i++){
            x = i;
            y = 3;
            for(int j=3;j>=0;j--){
                if(arr[i][j]!=0)    ch_arr[x][y--] = arr[i][j];
            }
        }
    }
    
    else if(d=='U'){
        for(int j=0;j<4;j++){
            x = 0;
            y = j;
            for(int i=0;i<4;i++){
                if(arr[i][j]!=0)    ch_arr[x++][y] = arr[i][j];
            }
        }
    }
    else {//D
        for(int j=0;j<4;j++){
            x = 3;
            y = j;
            for(int i=3;i>=0;i--){
                if(arr[i][j]!=0)    ch_arr[x--][y] = arr[i][j];
            }
        }
    }
    for(int i=0;i<4;i++){
        for(int j=0;j>4;j++){
            arr[i][j] = ch_arr[i][j];
            ch_arr[i][j] = 0;
        }
    }
}

void combine(char d){
    if(d=='L'){
        for(int i=0;i<4;i++){
            for(int j=0;j<3;j++){
                if(arr[i][j]==arr[i][j+1]){
                    arr[i][j] *= 2;
                    arr[i][j+1] = 0;
                }
            }
        }
    }
    else if(d=='R'){
        for(int i=0;i<4;i++){
            for(int j=3;j>0;j--){
                if(arr[i][j]==arr[i][j-1]){
                    arr[i][j] *= 2;
                    arr[i][j-1] = 0;
                }
            }
        }
    }
    
    else if(d=='U'){
        for(int j=0;j<4;j++){
            for(int i=0;i<3;i++){
                if(arr[i][j]==arr[i+1][j]){
                    arr[i][j] *= 2;
                    arr[i+1][j] = 0;
                }
            }
        }
    }
    else {//D
        for(int j=0;j<4;j++){
            for(int i=3;i>0;i--){
                if(arr[i][j]==arr[i-1][j]){
                    arr[i][j] *= 2;
                    arr[i-1][j] = 0;
                }
            }
        }
    }
}


int main(){
    char d;//‘L', ‘R’, ‘U’, 'D’ 
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++)    cin >> arr[i][j];
    }
    cin >> d;

    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++)    cout << arr[i][j] <<' ';
        cout<<endl;
    }
    cout<<endl;
    gravity(d);

    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++)    cout << arr[i][j] <<' ';
        cout<<endl;
    }
    cout<<endl;
    combine(d);

    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++)    cout << arr[i][j] <<' ';
        cout<<endl;
    }
    cout<<endl;
    gravity(d);
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++)    cout << arr[i][j] <<' ';
        cout<<endl;
    }
    //gravity(d);
    return 0;
    //중력작용
    //합치기
    //중력작용

}
