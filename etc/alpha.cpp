#include<iostream>
#include<string>
using namespace std;
 
int main(int argc, char** argv)
{
    int test_case;
    int T;

    cin>>T;
   
    for(test_case = 1; test_case <= T; ++test_case)
    {
        int cnt = 0;
        string tmp;
        cin >> tmp;
        for(int i=0;i<tmp.size();i++){
            if(97+i == tmp[i])  cnt++;
            else    break;
        }
        cout<<'#'<<test_case<<' '<<cnt<<'\n'; 
 
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
