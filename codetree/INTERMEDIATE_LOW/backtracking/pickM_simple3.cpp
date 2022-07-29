#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

int n,ans;
pair<int,int>start;
pair<int,int>end_p;

vector<pair<int,int>>picked;
vector<pair<int,int>>coin;

int cal(){//이동 거리 계산
    int result = 0;
    pair<int,int> cur = start;
    for(int i=0;i<picked.size();i++){// 이동하는 3개 코인
        result += abs(picked[i].first-cur.first) + abs(picked[i].second-cur.second);
        cur = picked[i];
    }
    result += abs(end_p.first-cur.first) + abs(end_p.second-cur.second);
    return result;
}

void Choose(int cur_num,int index){//3개의 코인 선택
    if(cur_num == 4){
        ans = min(ans,cal());
        return;
    }
    for(int i=index;i<coin.size();i++){
        picked.push_back(coin[i]);
        Choose(cur_num+1,i+1);
        picked.pop_back();
        
    }
}

int main(){
    cin >> n;
    char tmp;
    pair<int,int> tmp_coin[10];
	pair<int,int> stn={-1,-1};
	fill(tmp_coin,tmp_coin+10,stn);


   // tmp_coin.fill({-1,-1});
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>tmp;
            if(tmp == '.')  continue;
            else if(tmp == 'S'){//시작점
                start = make_pair(i,j);
            }
            else if(tmp == 'E'){//도착점
                end_p = make_pair(i,j);
            }
            else{
                tmp_coin[(int)(tmp-'1')] = make_pair(i,j);
            }
        }
    }
    for(int i=0;i<10;i++){
        if(tmp_coin[i].first>=0){
            coin.push_back(tmp_coin[i]);
        }
    }

    ans = INT_MAX;
    Choose(1,0);
    if(ans == INT_MAX)  cout<<-1;//불가능한 경우
    else    cout<<ans;
    return 0;

}
