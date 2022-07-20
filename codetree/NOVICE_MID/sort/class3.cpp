#include <iostream>
#include <algorithm>
using namespace std;

class Agent{
    public:
        char name;
        int score;
        Agent(char name=' ', int score=0){
            this->name = name;
            this->score = score;
        }
};

bool compare(Agent a, Agent b) {
    if (a.score < b.score)
        return true; 
    return false;

}

int main(){
    Agent agent[5];
    char n;
    int s;
    for(int i=0;i<5;i++){
        cin >> n >> s;
        agent[i] = Agent(n,s);
    }
    sort(agent,agent+5,compare);
    cout<<agent[0].name<<' '<<agent[0].score;

    return 0;

}
