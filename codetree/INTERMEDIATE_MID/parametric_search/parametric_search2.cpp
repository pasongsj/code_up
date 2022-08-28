#include <iostream>
using namespace std;
#define MAX_N 10000

int arr[MAX_N];
int n,m;

bool is_possible(int num){
    int cnt = 0;
    for(int i=0;i<n;i++){
        cnt += arr[i]/num;
    }
    return(cnt>=m);
}

int Find(){
    int left = 1, right = 100000, idx = 0;
    while(left <= right){
        int mid = (left + right)/2;
        if(is_possible(mid)){ //target < mid
            left = mid + 1;
            idx = max(idx,mid);
        }
        else{
            right = mid -1;
        }
    }
    return idx;
}


int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    cout<<Find();
    return 0;
}
