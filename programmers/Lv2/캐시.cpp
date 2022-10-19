#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    vector<string> cache;
    
    for(int i=0;i<cities.size();i++){
        string city = cities[i];
        transform(city.begin(), city.end(), city.begin(), ::tolower);//소문자로 변경
        
        auto it = find(cache.begin(), cache.end(), city);//cache에서 find index
        if(it == cache.end())   answer+=5;//캐쉬에 없음
        else{// 캐쉬에 있음
            cache.erase(it);
            answer+=1;
        }
        cache.push_back(city);//캐쉬에 추가
        
        while(cache.size()>cacheSize)  cache.erase(cache.begin());//캐쉬 사이즈 이상일경우 삭제
    }
    return answer;
}
