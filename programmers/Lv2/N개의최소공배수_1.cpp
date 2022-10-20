#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;



int solution(vector<int> arr) {
    int answer = 1;
    vector<int> prime = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
    
    for(int i=0;i<prime.size();i++){
        int max_time = 0;
        for(int j=0;j<arr.size();j++){
            int time = 0;
            while(arr[j]%prime[i] == 0){
                arr[j] /= prime[i];
                time++;
            }
            max_time = max(max_time,time);
        }
        answer*= pow(prime[i],max_time);
    }
    return answer;
}
