#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


bool solution(const char* s) {
    bool answer = true;
    if(s[0] == ')') answer = false;
    int num = 0;
    for(int i=0;i<strlen(s);i++){
        if(s[i] == '(') num++;
        else if(num > 0 && s[i] == ')')    num--;
    }
    if(num > 0) return false;
    
    return answer;
}
