#include <iostream>
#include <string>
using namespace std;

bool is_leap(int year){
    if(year%4 == 0 && year%100 != 0 || year%400 == 0)   return true;
    return false;
}

bool is_exist(int y,int m, int d){
    int last;
    if(m == 2)  last = (is_leap(y)?29:28); // 윤년인가
    else if(m<8 && m%2 == 1 || m>=8 && m%2 == 0)    last = 31;//31일 
    else    last = 30;//30일
    return (d<=last);
}

string weather(int M){
    if(3 <= M && M <= 5) return "Spring";
    else if(6 <= M && M <=8) return "Summer";
    else if(9 <= M && M <=11) return "Fall";
    else    return "Winter";
}

int main(){
    int Y, M, D;
    cin >> Y >> M >> D;
    //존재하는가
    if(is_exist(Y,M,D)){
        cout<<weather(M);
    }
    else    cout<<-1;
    return 0;
    
}
