#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

#define MAX_N 10000
int n, T;

int arr[MAX_N];

bool is_possible(int num){
    if(num>=n)   return true;
    priority_queue<int> stage;
    for(int i=0;i<n;i++){
        if(i<num){
            stage.push(T-arr[i]);
        }
        else{
            int tmp = stage.top()-arr[i];
            if(tmp<0)   return false;
            stage.pop();
            stage.push(tmp);
        }    
    }
    return true;
}

int main(){

    cin >> n >> T;

    for(int i=0;i<n;i++){
        cin >> arr[i];
    }


    int left =1, right = MAX_N, ans = MAX_N;
    while(left <=  right){
        int mid = (left + right)/2;
        if(is_possible(mid)){
            right = mid -1;
            ans = min(mid,ans);
        }
        else{ 
            left = mid + 1;
        }
    }
    cout<<ans;
    return 0;

}

