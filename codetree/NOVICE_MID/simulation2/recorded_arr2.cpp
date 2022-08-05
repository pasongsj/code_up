#include <iostream>
using namespace std;
#define MAX_N 100
int main(){
    int n,m,k,stu;
    int arr[MAX_N+1] = {0};
    cin >> n >> m >> k;
    for(int i=0;i<m;i++){
        cin >> stu;
        arr[stu]++;
        if(arr[stu]>=k){
            cout<<stu;
            return 0;
        }
    }
    cout<<-1;
    return 0;

}
