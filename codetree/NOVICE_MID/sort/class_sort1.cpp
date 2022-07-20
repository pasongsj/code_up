#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

//<, 오름차순 >, 내림차순 
class People{
    public:
        string name;
        int weight;
        int height;

        People(string name=" ", int weight=0, int height=0){
            this->name = name;
            this->weight = weight;
            this->height = height;
        }
};

bool cmp(People a, People b){
    return a.height<b.height;
}

int main(){
    int n;
    cin >> n;
    People p[n];
    for(int i=0;i<n;i++){
        cin>>p[i].name >> p[i].height >> p[i].weight;
    }
    sort(p,p+n,cmp);
    for(int j=0;j<n;j++){
        cout<<p[j].name<<' '<<p[j].height<<' '<<p[j].weight<<endl;
    }
    return 0;
}

