#include <iostream>
#include <string>
#include <tuple>
using namespace std;

class Character{
    public:
        string id;
        int level;

        Character(string id = " ",int level=0){
            this->id = id;
            this->level = level;
        }
};

int main(){
    Character user1 = Character("codetree",10);
    Character user2 = Character();
    cin>>user2.id>>user2.level;
    cout<<"user "<<user1.id <<' '<<"lv "<<user1.level<<endl;
    cout<<"user "<<user2.id <<' '<<"lv "<<user2.level<<endl;
    return 0;

}
