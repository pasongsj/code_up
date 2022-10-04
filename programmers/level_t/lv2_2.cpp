#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;
string cal_next(int n, string num){
    //십진수로
    unordered_map<char,int> S_toi={{'0',0},{'1',1},{'2',2},{'3',3},{'4',4},
                                  {'5',5},{'6',6},{'7',7},{'8',8},
                                  {'9',9},{'A',10},{'B',11},{'C',12},
                                  {'D',13},{'E',14},{'F',15}};
    int deci = 0;
    int tmp  = 1;
    for(int i=num.length()-1;i>=0;i--){
        deci += S_toi[num[i]]*tmp;
        tmp *= n;
    }
    deci++;

    //n진수로
    unordered_map<int,char> I_tos={{0,'0'},{1,'1'},{2,'2'},{3,'3'},{4,'4'},
                                  {5,'5'},{6,'6'},{7,'7'},{8,'8'},
                                  {9,'9'},{10,'A'},{11,'B'},{12,'C'},
                                  {13,'D'},{14,'E'},{15,'F'}};
    string ans = "";
    while(deci>0){
        ans = I_tos[deci%n] + ans;
        deci /= n;
    }
    return ans;

}

string solution(int n, int t, int m, int p) {
    string answer = "";
    string all_ans = "";
    string now = "0";
    while(all_ans.length()< t*m){
        all_ans += now;
        now = cal_next(n,now);//다음 진수 계산
    }
    for(int i=0;i<t;i++){
        answer += all_ans[m*i+p-1];
    }
    return answer;
}

