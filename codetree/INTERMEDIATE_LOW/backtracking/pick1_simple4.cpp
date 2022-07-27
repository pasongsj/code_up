#include <iostream>
#include <vector>
#include <utility>
using namespace std;


int n,k,result;
pair<int,int>line[16];
vector<int> ans;
bool is_overlap;

void Check(){
    int arr[1001] ={};
    for(int i=0;i<k;i++){
        for(int j = line[ans[i]].first;j<=line[ans[i]].second;j++){
            arr[j]++;
        }
    }
    for(int i=0;i<1001;i++){
        if(arr[i]>1){
            is_overlap = true;
            return;
        }
    }
    is_overlap = false;
    return;
}

void Choose(int cur_num,int back){
    if(cur_num == k+1){
        Check();
        if(is_overlap==false)   result = max(k,result);
        return;
    }
    for(int i=back+1;i<=n;i++){
        ans.push_back(i);
        Choose(cur_num+1,i);
        ans.pop_back();
    }

}

int main(){
    cin >> n;
    int a,b;
    for(int i=1;i<=n;i++){
        cin >> a >> b;
        line[i] = make_pair(a,b);
    }
    result = 0;
    for(k=n;k>0;k--){
        Choose(1,0);
        if(result>0)   break;
    }
    cout<<result;
    return 0;
}
