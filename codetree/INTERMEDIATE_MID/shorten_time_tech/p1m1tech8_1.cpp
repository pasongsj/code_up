#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;
#define MAX_N 100000

int seat[MAX_N+1];
int ans[MAX_N+1];
int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n;
    cin >> n;

    vector<tuple<int,int,int>> arr;//시간, 앉는지 일어나는지, index
    for(int i=1;i<=n;i++){
        int a,b;
        cin >> a >> b;
        arr.push_back(make_tuple(a,+1,i));
        arr.push_back(make_tuple(b,-1,i));
    }

    sort(arr.begin(),arr.end());

    for(int i=0;i<arr.size();i++){
        int time, situ, index;
        tie(time,situ,index) = arr[i];
        if(situ == 1){
            for(int i=1;i<=MAX_N+1;i++){
                if(seat[i] == 0){
                    seat[i] = index;
                    ans[index] = i;
                    break;
                }
            }
        }
        else{
            seat[ans[index]] = 0;
        }
    }
    for(int i=1;i<=n;i++){
        cout<<ans[i]<<' ';
    }
    return 0;

}
