#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class People{
    public:
        string name;
        int height;
        double weight;
        People(string name="",int height=0,int weight=0){
            this->name = name;
            this->height = height;
            this->weight = weight;
        }
};

bool cmp1(People a, People b){
    return a.name < b.name;
}
bool cmp2(People a, People b){
    return a.height > b.height;
}


int main(){
    People people[5];
    for(int i=0;i<5;i++){
        cin >> people[i].name >> people[i].height >> people[i].weight;
    }
    cout<<fixed;
    cout.precision(1);
    cout<<"name"<<endl;
    sort(people,people+5,cmp1);
    for(int i=0;i<5;i++){
        cout << people[i].name <<' '<< people[i].height <<' '<< people[i].weight << endl;
    }
    cout<<endl<<"height"<<endl;
    sort(people,people+5,cmp2);
    for(int i=0;i<5;i++){
        cout << people[i].name <<' '<< people[i].height <<' '<< people[i].weight << endl;
    }
    return 0;
}
