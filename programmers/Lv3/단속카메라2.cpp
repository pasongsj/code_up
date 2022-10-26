#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(vector<int> a,vector<int> b){
    return a[1] < b[1];
}

int solution(vector<vector<int>> routes) {
    int answer = 0;
    sort(routes.begin(),routes.end(),cmp);
    vector<int> camera;
    for(vector<int> i : routes){
        if(camera.empty()||i[0] > camera.back())  camera.push_back(i[1]);
    }
   
    answer = camera.size();
    return answer;
}
