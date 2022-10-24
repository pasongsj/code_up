
#include <string>
#include <vector>
#include <map>
using namespace std;

int solution(vector<vector<int>> routes) {
    int answer = 0;
    
    map<int,int> car;
    for (vector<int> i : routes){
        car[i[1]] = i[0];
    }
    vector<int> camera;
    for(auto it= car.begin();it!=car.end();it++){
        if(camera.empty()||it->second > camera.back())  camera.push_back(it->first);
    }
    answer = camera.size();
    return answer;
}
