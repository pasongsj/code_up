#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
int main(int argc, char** argv)
{
    int test_case;
    int T;
    T = 10;
    
    for(test_case = 1; test_case <= T; ++test_case)
    {
        int dump;
        cin >> dump;
        vector<int>arr;
        for(int i=0;i<100;i++){
            int tmp;
            cin >> tmp;
            arr.push_back(tmp);
        }
 
        for(int i=0;i<dump;i++){
            arr[max_element(arr.begin(),arr.end())- arr.begin()]--;
            arr[min_element(arr.begin(),arr.end())- arr.begin()]++;
        }
        cout<<'#'<< test_case <<' '<<*max_element(arr.begin(),arr.end()) - *min_element(arr.begin(),arr.end())<<'\n'; 
 
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
