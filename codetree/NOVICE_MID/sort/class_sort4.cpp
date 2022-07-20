#include <iostream>
#include <algorithm>
using namespace std;

class Students{
    public:
        int height;
        int weight;
        int num;
        Students(int height=0, int weight=0, int num=0){
            this->height = height;
            this->weight = weight;
            this->num = num;
        }
};

//내림차순 >
bool cmp(Students a, Students b){
    if(a.height == b.height){
        if(a.weight == b.weight){
            return a.num<b.num;
        }
        return a.weight>b.weight;
    }
    return a.height>b.height;
}
int main(){
    int n;
    cin >> n;
    Students students[n];
    for(int i=0;i<n;i++){
        cin >> students[i].height >> students[i].weight;
        students[i].num = i+1;
    }
    sort(students,students+n,cmp);

    for(int i=0;i<n;i++){
        cout << students[i].height <<' '<< students[i].weight <<' '<< students[i].num << endl;
    }
    return 0;
}
