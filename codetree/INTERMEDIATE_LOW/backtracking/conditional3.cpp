#include <iostream>
#include <vector>
using namespace std;

vector<int> num;
int n;
bool is_print;

void Print(){//print
    for(int i=0;i<num.size();i++)   cout<<num[i];
    cout<<endl;
}

bool compare(int a,int b,int len){//a-(len-1)~a, b-(len-1)~b 비교 
    for(int i=0;i<len;i++){
        if(num[a-i] != num[b-i])  return false;
    }
    return true;
}


bool possible(){
    int len,l1 = 0,l2 = num.size()-1;// 앞 마지막, 뒷 마지막
    int tmp = num.back();//마지막 push_back

    for(int i=l2-1;i>=(l2)/2;i--){
        if(num[i] == tmp){
            l1 = i;//비교대상 마지막점
            len = l2-l1;
            if(compare(l1,l2,len)) return false;
        }
    }
    return true;
}

void Choose(int cur_num){
    if(cur_num == n+1){
        Print();
        exit(0);
    }

    for(int i=4;i<=6;i++){
        num.push_back(i);
        if(cur_num==1 || possible()){
            Choose(cur_num+1);
        }
        num.pop_back();
    }
}


int main(){
    cin >> n;
    is_print = true;
    Choose(1);
    return 0;
}
