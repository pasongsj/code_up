#include <iostream>
#include <vector>
using namespace std;
vector <int> ans;
int n,m;
void Print(){
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<' ';
        //if(ans[i]==1)   cout<<i+1<<' ';
    }
    cout<<endl;
}
//count(set.begin(), set.end(), num)
void Choose(int cur_num,int back){
    if(cur_num == m+1){
        Print();
        //if(cnt == m)    Print();
        return;
    }
    for(int i=back+1;i<=n;i++){
        ans.push_back(i);
        Choose(cur_num+1,i);
        ans.pop_back();
    }
}
int main(){
    cin >> n >> m;
    Choose(1,0);
    return 0;

}
