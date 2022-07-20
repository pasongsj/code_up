#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Location{
    public:
        string name;
        string street;
        string locate;
        Location(string name=" ",string street=" ",string locate=" "){
            this->name = name;
            this->street = street;
            this->locate = locate;
        }
};

bool compare(Location a, Location b) {
    if (a.name > b.name)//내림차순
        return true; 
    return false;

}

int main(){
    int n;
    string a,b,c;
    cin >> n;
    Location people[n];
    for(int i=0;i<n;i++){
        cin >> a >> b >> c;
        people[i] = Location(a,b,c);
    }
    sort(people,people+n,compare);
    cout<<"name "<<people[0].name<<endl;
    cout<<"addr "<<people[0].street<<endl;
    cout<<"city "<<people[0].locate<<endl;
    return 0;
}
