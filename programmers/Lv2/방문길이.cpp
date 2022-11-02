#include <string>
#include <set>
#include <unordered_map>
#include <tuple>
using namespace std;

bool in_range(int x, int y){
    return (0<=x &&x<=10 && 0<=y && y<=10);
}

int solution(string dirs) {
    int answer = 0;
    set<tuple<int,int,int>> point;
    unordered_map<char,int> d = {{'U',0},{'D',1},{'R',2},{'L',3}};
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,1,-1};
    int cx = 5, cy = 5;
    for(char i:dirs){
        int  nx = cx + dx[d[i]], ny = cy + dy[d[i]];
        if(!in_range(nx,ny))    continue;
        if(i == 'R')    point.insert(make_tuple(cx,cy,0));
        else if(i == 'U')   point.insert(make_tuple(cx,cy,1));
        else if(i == 'L')   point.insert(make_tuple(nx,ny,0));
        else    point.insert(make_tuple(nx,ny,1));
        cx = nx, cy = ny;
    }
        
        
    answer = point.size();
    return answer;
}
