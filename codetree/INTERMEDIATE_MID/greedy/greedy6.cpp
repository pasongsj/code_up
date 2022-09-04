#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>

using namespace std;
#define RAN 1e8

bool cmp(long long a,long long b){
    int tmpa = a,tmpb = b;
    return tmpa*pow(10,to_string(b).size())+tmpb > tmpb*pow(10,to_string(a).size())+tmpa;

}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n;
    cin >> n;
    vector<long long> arr;
    for(int i=0;i<n;i++){
        long long tmp;
        cin >> tmp;
        arr.push_back(tmp);
    }

    sort(arr.begin(),arr.end(),cmp);
    for(int i=0;i<n;i++){
        cout<<arr[i];
    }
    return 0;
}
