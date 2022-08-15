#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_N 101
class Event{
    public:
        int x;
        int y;
        int time;
        Event(int x=0,int y=0, int time = 0){
            this->x = x;
            this->y = y;
            this->time = time;
        }
};

bool cmp(Event a,Event b){
    return a.time<b.time;
}

int main(){
    int N,K,P,T;
    cin >> N >> K >> P >> T;// N명 K번 전염 P번에서 전염시작 T번 악수
    //int x,y,t;
    Event acc[250];
    int infected[MAX_N] = {false};
    infected[P] = 1;


    for(int i=0;i<T;i++){
        cin>>acc[i].time>>acc[i].x>>acc[i].y;
    }
    sort(acc,acc+T,cmp);

    for(int i=0;i<T;i++){
        int tmpx = infected[acc[i].x], tmpy = infected[acc[i].y];
        if(0<tmpx && tmpx<=K || 0<tmpy && tmpy<=K){
            infected[acc[i].x]++;
            infected[acc[i].y]++;
        }
    }

    for(int i=1;i<=N;i++){
        if(infected[i]>0)   cout<<1;
        else cout<<0;
    }
    
    return 0;
}
