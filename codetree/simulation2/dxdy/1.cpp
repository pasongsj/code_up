#include <iostream>
#include <map>
using namespace std;
int main(){
    map<char, int> d_x = {
        {'E',1},
        {'S',0},
        {'W',-1},
        {'N',0},
    };
    map<char, int> d_y = {
        {'E',0},
        {'S',-1},
        {'W',0},
        {'N',1},
    };
    int x = 0,y = 0,n,mov;
    char direc;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> direc >> mov;
        x += d_x[direc]*mov;
        y += d_y[direc]*mov;

