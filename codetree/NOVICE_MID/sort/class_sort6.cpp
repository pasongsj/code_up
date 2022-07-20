#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class People{
    public:
        string name;
        int height;
        int weight;
        People(string name="",int height=0,int weight=0){
            this->name = name;
            this->height = height;
            this->weight = weight;
        }
};

bool cmp(People a, People b){
    if(a.height == b.height){
        return a.weight > b.weight;
    }
    return a.height < b.height;
}


int main(){
    int n;
    cin >> n;
    People people[n];
    for(int i=0;i<n;i++){
        cin >> people[i].name >> people[i].height >> people[i].weight;
    }

    sort(people,people+n,cmp);
    for(int i=0;i<n;i++){
        cout << people[i].name <<' '<< people[i].height <<' '<< people[i].weight << endl;
    }
    
    return 0;
}
