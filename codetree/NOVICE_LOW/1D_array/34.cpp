#include <iostream>
#include <climits>
using namespace std;
int main(){
    int n,a,first_max = INT_MIN, second_max;
    cin >> n;
    for(int i=0;i<n;i++){
        cin>>a;
        if(a>=first_max){
            second_max = first_max;
            first_max = a;
        }
        else if(a>second_max)   second_max = a;
    }
    cout<< first_max <<' ' << second_max;
    return 0;
}
