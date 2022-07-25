#include <iostream>
#include <vector>
using namespace std;
int n,cnt = 0;
vector<int> ans;


void Print(){
    cout<<cnt<<endl;
    for(int i=0;i<ans.size();i++)   cout<<ans[i];
    cout<<endl;
}
bool is_beautiful(){
    int before = 1;
    int cnt = 1;
    for(int i=0;i<ans.size();i++){
        if(before == 1){
            before = ans[i];
            cnt = 1;
        }
        else if(before == ans[i]) cnt++;
        else{
            if(cnt % before !=0){
            //    cout<<"Here";
                return false;
            }
            before = ans[i];
            cnt = 1;
        }
    }
 //   cout<<cnt % before<<' ';
    if(cnt % before !=0){
        return false;
    }
    return true;

}

void get_num(int cur_num){//m은 자리 수
    if(cur_num == n){
        if(is_beautiful())    cnt++;
    //    Print();
        return;
    }
    for(int i=1;i<=4;i++){
        ans.push_back(i);
        get_num(cur_num+1);
        ans.pop_back();
    }
    
}

int main(){
    cin >> n;
    get_num(0);
    cout<<cnt;
    return 0;
}
