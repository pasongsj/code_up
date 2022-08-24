#include <iostream>

#define MAX_N 100000
#define MAX_A 1000000

using namespace std;

int n, q;
int arr[MAX_N + 1];
int prefix_sum[MAX_A + 1];

int GetSum(int s, int e) {
    if(s == 0) return prefix_sum[e];
    return prefix_sum[e] - prefix_sum[s - 1];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> q;
    for(int i = 1; i <= n; i++) {
        cin >> arr[i];
        prefix_sum[arr[i]]++;
    }
    for(int i = 1; i <= MAX_A; i++)
        prefix_sum[i] += prefix_sum[i - 1];
    
    for(int i = 1; i <= q; i++) {
        int l, r;
        cin >> l >> r;
        cout << GetSum(l, r) << endl;
    }
    return 0;
}
