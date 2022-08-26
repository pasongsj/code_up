#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <queue>
using namespace std;
#define MAX_N 100000

int ans[MAX_N+1];
int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n;
    cin >> n;

    vector<tuple<int,int,int>> arr;//시간, 앉는지 일어나는지, index

    priority_queue<int> computers;// 컴퓨터 자리
    for(int i=1;i<=n;i++){
        int a,b;
        cin >> a >> b;
        arr.push_back(make_tuple(a,+1,i));
        arr.push_back(make_tuple(b,-1,i));
        computers.push(-i);
    }


    sort(arr.begin(),arr.end());

    for(int i=0;i<arr.size();i++){
        int time, situ, index;
        tie(time,situ,index) = arr[i];
        if(situ == 1){//시작 자리 차지하기
            ans[index] = -computers.top();
            computers.pop();
        }
        else{//끝 자리 돌련놓기
            computers.push(-ans[index]);
        }
    }
    for(int i=1;i<=n;i++){
        cout<<ans[i]<<' ';
    }
    return 0;

}
