#include <iostream>
#include <climits>
using namespace std;
#define MAX_N 100000
int arr[MAX_N];
int score[MAX_N];

int main(){
    int n;
    cin >> n;
    cin >> arr[0];
    score[0] = arr[0];
    int max_val = score[0];
    for(int i=1;i<n;i++){
        cin >> arr[i];
        score[i] = max(arr[i],score[i-1]+arr[i]);
        max_val = max(max_val,score[i]);
    }
    cout<<max_val;
    return 0;


}
