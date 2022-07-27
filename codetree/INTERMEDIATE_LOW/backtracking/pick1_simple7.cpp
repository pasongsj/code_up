#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

vector<int> num;
int ans;
//char a[100];//문자 a b c d e f 6개  index = n/2+1
//char c[100];//연산자 + - * index = n/2
string s;

int cal(){
    char tmp[6] = {'a', 'b' ,'c' ,'d' ,'e' ,'f'};
    map<char,int> cti;
    for(int i=0;i<6;i++){
        cti.insert({tmp[i],num[i]});
    }
    if(s.length()==1)   return 4;
    int tmp_n[100];
    char tmp_c[100];
    int index_n = 0,index_c = 0;
    for(int i=0;i<s.length();i++){//숫자, 연산자 분리
        if(i%2 == 0)    tmp_n[index_n++]=cti[s[i]];
        else    tmp_c[index_c++] = s[i];
    }

    int index = 0;
    int result = tmp_n[index++];//첫번째 숫자

    //연산
    for(int j=0;j<index_c;j++){
        if(tmp_c[j]=='+'){
            result = result + tmp_n[index++];
        }
        else if(tmp_c[j]=='-'){
            result = result - tmp_n[index++];
        }
        else{
            result = result * tmp_n[index++];
        }
    }
    return result;
}


void Choose(int cur_num){//a b c d e f에 1~4 할당한 모든 경우의 수
    if(cur_num == 7){
        ans = max(ans,cal());
        return;
    }
    for(int i=1;i<=4;i++){
        num.push_back(i);
        Choose(cur_num+1);
        num.pop_back();
    }
}

int main(){
    cin >> s; 
    ans = 0;

    Choose(1);
    cout<<ans;

    return 0;
}
