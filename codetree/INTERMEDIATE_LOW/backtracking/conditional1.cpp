#include <iostream>
#include <vector>
using namespace std;
int k, n;
vector<int> ans;

void Print(){
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<' ';
    }
    cout<<endl;
}


void Choose(int curr_num,int backback){
    int tmp;
    if(curr_num == n+1){
        Print();
        return;
    }
    for(int i=1;i<=k;i++){
        if(curr_num == 1 || !(ans.back()==i && backback==i)){
            if(curr_num == 1)   tmp = 0;
            else tmp = ans.back();
            ans.push_back(i);
            Choose(curr_num+1,tmp);
            ans.pop_back();
        }
    }
}
int main(){
    cin>>k>>n;
    Choose(1,0);
    return 0;

}
