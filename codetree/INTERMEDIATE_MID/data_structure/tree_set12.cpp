#include <iostream>
#include <set>
#include <string>
#include <utility>

using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
//rc x == 1 난이도 최상, 가장 높은 번호
//rc x == -1 난이도 최하, 가장 낮은 번호 --> sorted
//ad P L --> L난이도, P번 추가
//sv P L --> L난이도, P번 제거
    int n,m;
    cin >> n;
    set<pair<int,int>> prob;
    for(int i=0;i<n;i++){
        int P, L;
        cin >> P >> L;
        prob.insert(make_pair(L,P));
    }

    cin >> m;
    for(int i=0;i<m;i++){
        string s;
        int P,L;
        cin >> s;
        if(s=="ad"){
            cin >> P >> L;
            prob.insert(make_pair(L,P));
        }
        else if(s=="sv"){
            cin >> P >> L;
            prob.erase(make_pair(L,P));
        }
        else{
            int x;
            cin >> x;
            if(x>0) cout<<(*prob.rbegin()).second<<'\n';
            else    cout<<(*prob.begin()).second<<'\n';
        }
    }   
    return 0;
}
