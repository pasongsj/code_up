#include <iostream>
using namespace std;
#define MAX_N 10
class NUM{
    public:
        int numI;
        int numJ;
        int numK;
        int a;
        int b;
        NUM(int numI=0,int numJ=0,int numK=0,int a=0, int b=0){
            this->numI = numI;
            this->numJ = numJ;
            this->numK = numK;
            this->a = a;
            this->b = b;
        }
};

bool is_count(NUM cur,int i,int j,int k){
    int countA = 0, countB = 0;

    if(cur.numI == i)   countA++;
    else if(cur.numI == j || cur.numI == k) countB++;

    if(cur.numJ == j)   countA++;
    else if(cur.numJ == i || cur.numJ == k) countB++;

    if(cur.numK == k)   countA++;
    else if(cur.numK == i || cur.numK == j) countB++;
    
    if(countA == cur.a && countB == cur.b)  return true;
    return false;
}
int main(){
    //같은 위치 - 1번카운트 증가
    //같은숫자+다른위치 - 2번카운트 증가 
    int n,tmp,ans = 0;
    NUM arr[MAX_N];
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> tmp >> arr[i].a >> arr[i].b;
        arr[i].numK = tmp%10;
        tmp/=10;
        arr[i].numJ = tmp%10;
        tmp/=10;
        arr[i].numI = tmp%10;
    }
    for(int i=1;i<=9;i++){
        for(int j=1;j<=9;j++){
            for(int k=1;k<=9;k++){
                bool is_col = true;
                for(int l=0;l<n;l++){
                    if(!is_count(arr[l],i,j,k)||i==j||j==k||k==i){
                        is_col = false;
                        break;
                    }
                }
                if(is_col)  ans++;
            }
        }
    }
    cout<<ans;
    return 0;
}
