#include <iostream>
#include <algorithm>
using namespace std;

class Num{
    public:
        int n;
        int pos;
        int after_pos;
        Num(int n=0,int pos=0,int after_pos=0){
            this->n = n;
            this->pos = pos;
            this->after_pos = after_pos;
        }
};

bool cmp1(Num a, Num b){
    if(a.n==b.n){
        return a.pos<b.pos;
    }
    return a.n<b.n;
}

bool cmp2(Num a, Num b){
    return a.pos<b.pos;
}


int main(){
    int n;
    cin >> n;
    Num nums[n];
    for(int i=0;i<n;i++){
        cin>>nums[i].n;
        nums[i].pos = i+1;
    }
    sort(nums,nums+n,cmp1);
    for(int i=0;i<n;i++){
        nums[i].after_pos = i+1;
    }
    sort(nums,nums+n,cmp2);
    for(int i=0;i<n;i++){
        cout<<nums[i].after_pos<<' ';
    }
    return 0;
}
