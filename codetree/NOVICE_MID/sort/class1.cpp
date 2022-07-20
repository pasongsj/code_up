#include <iostream>
#include <string>
using namespace std;
class Meeting {
    public:
        string code;
        char point;
        int time;

        Meeting(string code, char point, int time) {
            this->code = code;
            this->point = point;
            this->time = time;
        }
};
int main(){
    string x;
    char y;
    int z;
    cin >> x >> y >> z;
    Meeting a = Meeting(x,y,z);

    cout<<"secret code : "<<a.code<<endl;
    cout<<"meeting point : "<<a.point<<endl;
    cout<<"time : "<<a.time<<endl;
    return 0;
}

