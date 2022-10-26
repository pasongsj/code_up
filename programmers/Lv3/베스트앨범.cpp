#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

static bool cmp(pair<string,int>&a, pair<string,int>&b){
    return a.second>b.second;
}
static bool cmp2(pair<int,int>&a, pair<int,int>&b){
    if(a.first == b.first) return a.second<b.second;
    return a.first > b.first;
}
vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    
    map<string,int> ge;
    map<string,vector<pair<int,int>>> pl;
    
    for(int i=0;i<genres.size();i++){
        ge[genres[i]] += plays[i];
        pl[genres[i]].push_back(make_pair(plays[i],i));
    }
    vector<pair<string,int>> sort_gen (ge.begin(),ge.end());
    sort(sort_gen.begin(),sort_gen.end(),cmp);
    
    for(int i=0;i<sort_gen.size();i++){
        string gen = sort_gen[i].first;
        sort(pl[gen].begin(),pl[gen].end(),cmp2);
        int lim = (pl[gen].size() > 2 ? 2 : pl[gen].size());
        for(int i=0;i<lim;i++){
            answer.push_back(pl[gen][i].second);
        }
    }
    
    return answer;
}
