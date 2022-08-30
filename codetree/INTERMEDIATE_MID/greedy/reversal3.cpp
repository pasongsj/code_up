#include <iostream>
#include <string>
using namespace std;
#define MAX_N 1000


bool arr[MAX_N];

int main(){
    int n,ans = 0;
    string s, e;
    cin >> n >> s >> e;
    
    bool is_flip = false;
    for(int i=n-1;i>=0;i--){
        if(is_flip){
            if(s[i]==e[i]){
                is_flip = false;
                ans++;
            }
        }
        else{
            if(s[i]!=e[i]){
                is_flip = true;
                ans++;
            }
        }
    }

    cout<<ans;
    return 0;
}
