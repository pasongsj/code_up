#include <iostream>
#include <algorithm>
using namespace std;
int x, y;

int Sum(int n) {
    if(n < 10)
        return n;
    else
        return Sum(n / 10) + (n % 10);
}

int main() {
    cin >> x >> y;

    int ans = 0;
    for(int i = x; i <= y; i++)
        ans = max(ans, Sum(i));
    
    cout << ans;
    return 0;
}
