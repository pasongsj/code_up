#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    sort(citations.begin(),citations.end());
    
    map<int,int> arr;
    for(int i=citations.size()-1;i>=0;i--){
        arr[citations[i]] = citations.size()-i;
    }
    
    int mid, left = 0, right = 10000;
    while(left<right){
        mid = (left + right)/2;
        map<int,int>::iterator it = arr.lower_bound(mid);
        
        if(mid == it->second)   break;
        else if(it == arr.end()||it->second <= mid){
            right = mid;
        }
        else{
            left = mid + 1;
        }
    }
    answer = mid;
    return answer;
}
