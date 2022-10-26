#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int n, vector<int> statsions, int w)
{
    int answer = 0;
    stations.push_back(n+w+1); // 끝 station추가
  //  stations.push_back(-w); // 첫 station추가  
  //  sort(stations.begin(),stations.end());
    for(int i=0;i<stations.size()-1;i++){
        int range = (stations[i+1]-stations[i]-1);
        if(range>0) answer += range/(2*w+1);
    }
    int tmp = stations[0] - (-w) -1;
    if(tmp>0)   answer += tmp/(2*w+1);

    return answer;
}
