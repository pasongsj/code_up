#include <iostream>
#include <string>
using namespace std;

class Bomb{
    public:
        string code;
        char color;
        int sec;
        Bomb(string code = " ",char color = ' ', int sec = 0){
            this->code = code;
            this->color = color;
            this->sec = sec;
        }
};
int main(){
    Bomb bom;
    cin >> bom.code >> bom.color >> bom.sec;

    cout<<"code : "<<bom.code<<endl;
    cout<<"color : "<<bom.color<<endl;
    cout<<"second : "<<bom.sec<<endl;
    return 0;
}
