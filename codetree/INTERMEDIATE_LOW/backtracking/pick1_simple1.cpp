#include <iostream>
#include <vector>
using namespace std;
int k,n;
vector<int> ans;


void Print(){
    for(int i=0;i<ans.size();i++)   cout<<ans[i]<<' ';
    cout<<endl;
}
void get_num(int m){//m은 자리 수
    if(m == n){
        Print();
        return;
    }
    for(int i=0;i<k;i++){
        ans.push_back(i+1);
        get_num(m+1);
        ans.pop_back();
    }
    
}

int main(){
    cin >> k >> n;
    get_num(0);
    return 0;
}
//1,2,3 //1,2,3
