#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;
int main(){
    unordered_map<int,int> month = {{1,31},{2,29},{3,31},{4,30},{5,31},{6,30},{7,31},{8,31},{9,30},{10,31},{11,30},{12,31}};
    unordered_map<string,int> d = {{"Mon",0}, {"Tue",1}, {"Wed",2}, {"Thu",3}, {"Fri",4}, {"Sat",5}, {"Sun",6}};

    int m1,d1,m2,d2;
    cin >> m1 >> d1 >> m2 >> d2;

    string day;
    cin >> day;

    int a1 = d1 + d[day], a2 = d2+7;
    for(int i=1;i<m1;i++)   a1 += month[i];
    for(int i=1;i<m2;i++)   a2 += month[i];

    cout<<(a2-a1)/7;
    return 0;
}
