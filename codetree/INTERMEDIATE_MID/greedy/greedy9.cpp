#include <iostream>
#include <set>
using namespace std;
#define MAX_N 50000

int arr[MAX_N];
set<int> cardA;
int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, ans = 0;
    cin >> n;

    for(int i=1;i<=2*n;i++) cardA.insert(i);

    for(int i=0;i<n;i++){
        cin>>arr[i];
        cardA.erase(arr[i]);
    }

    for(int i=0;i<n;i++){
        if(cardA.upper_bound(arr[i])!= cardA.end()){
            cardA.erase(*cardA.upper_bound(arr[i]));
            ans++;
        }
    }
    cout<<ans;

    return 0;
}
