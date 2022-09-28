#include <iostream>
#include <tuple>
using namespace std;

#define MAX_N 100
pair<long long,long long> arr[MAX_N];
int main(){
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        long long x,y;
        cin >> x >> y;
        arr[i] = make_pair(x,y);
    }
    long long ans = 0;
    for(int i=0;i<n;i++){
        long long x1,y1;
        tie(x1,y1) = arr[i];
        for(int j=i+1;j<n;j++){
            long long x2,y2;
            tie(x2,y2) = arr[j];
            for(int k=j+1;k<n;k++){
                long long x3,y3;
                tie(x3,y3) = arr[k];
                if((x1 == x2 || x2 == x3 || x3 == x1) && (y1 == y2 || y2 == y3 || y3 == y1)){
                    long long s = abs((x1*y2 + x2*y3 + x3*y1) - (x2*y1 + x3*y2 + x1*y3));
                    ans = max(ans,s);
                }
            }
        }
    }
    cout<<ans;
    return 0;
}
