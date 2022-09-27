#include <iostream>
#include <vector>
#include <tuple>
#include <climits>
using namespace std;

#define MAX_N 100
pair<int,int> arr[MAX_N];
int main(){
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        int x,y;
        cin >> x >> y;
        arr[i] = make_pair(x,y);
    }

    int ans = INT_MAX;
    for(int i=0;i<n;i++){
        int cur_x,cur_y;
        tie(cur_x,cur_y) = arr[i];
        for(int j=i+1;j<n;j++){
            int n_x,n_y;
            tie(n_x,n_y) = arr[j];
            ans = min(ans, (cur_x - n_x)*(cur_x - n_x) + (cur_y - n_y)*(cur_y - n_y));
        }
    }
    cout<<ans;
        return 0;
}
