#include <iostream>
#include <string>
using namespace std;
int main(){
    string str,obj_str;
    int num,i;
    bool is_same = false;
    cin >> str >> obj_str;
    for(i=0;i<str.length();i++){
        if(str[i]== obj_str[0]){
            is_same = true;
            for(int j=1;j<obj_str.length();j++){
                if(str[i+j]!=obj_str[j]){
                    is_same = false;
                    break;
                }
            }
        }
        if(is_same == true){
            break;
        }
    }
    if(is_same == true) cout<<i;
    else    cout<<-1;
    return 0;

