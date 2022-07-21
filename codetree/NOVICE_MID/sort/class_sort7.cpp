#include <iostream>
#include <algorithm>

using namespace std;

class Position{
    public:
        int x;
        int y;
        int num;
        Position(int x=0,int y=0,int num=0){
            this->x = x;
            this->y = y;
            this->num = num;
        }
};

//오름차순 <
bool cmp(Position a, Position b){
    if(abs(a.x)+abs(a.y)==abs(b.x)+abs(b.y)){
        return a.num<b.num;
    }
    return abs(a.x)+abs(a.y) < abs(b.x)+abs(b.y);
}

int main(){
    int n;
    cin >> n;
    Position point[n];
    for (int i=0;i<n;i++){
        cin>>point[i].x>>point[i].y;
        point[i].num = i+1;
    }
    sort(point,point+n,cmp);
    for(int i=0;i<n;i++){
        cout<<point[i].num<<endl;
    }
    return 0;
}
