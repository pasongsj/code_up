#include <iostream>
#include <climits>
using namespace std;
int main(){
    int n,max_val,index,tmp;
    cin >> n;
    int m[n];
    tmp = n;
    for(int i=0;i<n;i++){
        cin>>m[i];
    }
    while (tmp>0){
        max_val = INT_MIN;
        for(int j=0;j<tmp;j++){
            if(m[j]>max_val){
                max_val = m[j];
                index = j;
            }
        }
        cout<< index + 1<< ' ';
        tmp = index;
    }

    return 0;
}
