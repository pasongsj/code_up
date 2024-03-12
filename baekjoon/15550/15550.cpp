#include <iostream>
using namespace std;
int main() {
	int a = 999999998;
    float b = 999999999;
	long long c = 999999999;
    if (a == b && b == c && c != a) {
        cout << "true" << '\n';
    }
    else {
        cout << "false" << '\n';
    }
    return 0;
}