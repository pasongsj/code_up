#include <iostream>
#include <vector>
using namespace std;
#define MAX_N 20

int arr[MAX_N];
int n, m,ans;
vector<int> picked;

void cal(){
    int tmp = 0;
    for(int i=0;i<picked.size();i++){
        tmp = tmp^picked[i];
    }
    ans = ans>tmp?ans:tmp;
}

void Choose(int cur_num,int index){
    if(cur_num == m+1){
        cal();
        return;
    }
    for(int i=index;i<n;i++){
        picked.push_back(arr[i]);
        Choose(cur_num+1,i+1);
        picked.pop_back();
    }
}

int main(){
    cin >> n >> m;
    for(int i=0;i<n;i++)    cin >>arr[i];
    ans = 0;
    Choose(1,0);
    cout<<ans;
    return 0;
}
