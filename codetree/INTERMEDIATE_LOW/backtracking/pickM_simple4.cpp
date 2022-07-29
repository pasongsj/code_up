#include <iostream>
#include <climits>
#include <vector>
using namespace std;
#define MAX_N 20
int n,sum,ans;
int arr[MAX_N*2];
vector<int> picked;

int cal(){
    int sum_half = 0;
    for(int i=0;i<picked.size();i++){
        sum_half+= picked[i];
    }
    return abs(sum - 2*sum_half);
}

void Choose(int cur_num,int index){
    if(cur_num == n+1){
        ans = min(ans,cal());
        return;
    }
    for(int i=index;i<2*n;i++){
        picked.push_back(arr[i]);
        Choose(cur_num+1,i+1);
        picked.pop_back();
    }
}

int main(){
    cin >> n;
    sum = 0;
    for(int i=0;i<2*n;i++){
        cin>>arr[i];
        sum += arr[i];
    }
    ans = INT_MAX;
    Choose(1,0);
    cout<<ans;
    return 0;
}
