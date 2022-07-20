#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Subject{
    public:
        string name;
        int kor;
        int eng;
        int mat;
        Subject(string name=" ",int kor=0,int eng=0, int mat=0){
            this->name=name;
            this->kor=kor;
            this->eng=eng;
            this->mat=mat;
        }
};
// < 오름차순
bool cmp(Subject a, Subject b){
    return a.kor + a.eng + a.mat < b.kor + b.eng + b.mat;
}

int main(){
    int n;
    cin >> n;
    Subject stud[n];
    for(int i=0;i<n;i++){
        cin >> stud[i].name >> stud[i].kor >> stud[i].eng >> stud[i].mat;
    }
    sort(stud,stud+n,cmp);

    for(int i=0;i<n;i++){
        cout<<stud[i].name<<' '<<stud[i].kor<<' '<<stud[i].eng<<' '<<stud[i].mat<<endl;
    }
    return 0;
}
