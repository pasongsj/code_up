#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    if(arr.size()==0)   return answer;

    int last = arr[0];
    answer.push_back(arr[0]);

    for(int i=1;i<arr.size();i++){
        if(arr[i] == last)  continue;
        answer.push_back(arr[i]);
        last = arr[i];
    }
    return answer;
}
