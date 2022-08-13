#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX_N 101


char arr[MAX_N];
vector<int> position;
int main(){
    int n, pos, ans = 0;
    char sign;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> pos >> sign;
        arr[pos] = sign;
        position.push_back(pos);
    }
    sort(position.begin(),position.end());

    for(int i=0;i<position.size();i++){
        for(int j=i+1;j<position.size();j++){
            int tmp = 0;
            for(int k=i;k<=j;k++){
                if(arr[position[k]] == 'G') tmp++;
                else if(arr[position[k]] =='H')   tmp--;
            }
            if(tmp == 0){
                ans = max(ans,position[j]-position[i]);
            }
        }
    }
    cout<< ans;
    return 0;
}

