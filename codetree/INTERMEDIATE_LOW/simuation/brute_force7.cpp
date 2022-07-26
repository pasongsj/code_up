#include <iostream>
using namespace std;
#define MAX_N 20

int arr[MAX_N][MAX_N];
int n,m,ans = -1;
int get_max(int x, int y){
    if(arr[x][y]<0) return -1;
    for(int i=n-1;i>=x;i--){
        for(int j=m-1;j>=y;j--){
            //x,y부터 i,j까지  양수인지 확인
            bool is_natural = true;
            for(int a=x;a<=i;a++){
                for(int b=y;b<=j;b++){
                    if(arr[a][b]<=0){
                        is_natural = false;
                        break;
                    }
                }
                if(!is_natural) break;//양수가 아니면 break;
            }
            if(is_natural&&ans<(i-x+1)*(j-y+1)){//for문을 정상적으로 다 돈경우 = 양수 직사각형
                ans = (i-x+1)*(j-y+1); // ans 큰값으로 갱신
            }
        }
    }
    return ans;
    
}
int main(){
    cin >> n >>m;
    //입력
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) cin>>arr[i][j];
    }

    int tmp,ans = -1;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            //기준점 i j
            tmp = get_max(i,j);
            if(tmp > ans)   ans = tmp; // 큰값 교체
        }
    }
    cout<<ans;
    return 0;
}
