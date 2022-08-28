#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_N 100000

int n, m;
int point[MAX_N];

int upper_bound(int num){
    int idx = n, left = 0, right = n-1;
    while(left<=right){
        int mid = (left + right)/2;
        if(point[mid]>num){
            idx = min(idx,mid);
            right =mid -1;
        }
        else    left = mid + 1;
    }
    return idx;
}

int lower_bound(int num){
    int idx = n, left = 0, right = n-1;
    while(left<=right){
        int mid = (left + right)/2;
        if(point[mid]>=num){
            idx = min(idx,mid);
            right = mid -1;
        }
        else    left = mid +1;
    }
    return idx;
}

int main(){
    cin >> n >> m;
    for(int i=0;i<n;i++)    cin >> point[i];
    sort(point,point+n);

    for(int i=0;i<m;i++){
        int a,b, cnt;
        cin >> a >> b;//b의 upperbound - a의 lowerbound
        cnt = upper_bound(b)-lower_bound(a);
        cout<<cnt<<'\n';
    }
    return 0;
}
