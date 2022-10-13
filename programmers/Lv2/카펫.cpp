#include <string>
#include <vector>
#include <cmath>
using namespace std;

vector<int> solution(int brown, int yellow) {
    int tmp = ((brown/2-2) + sqrt(pow((brown/2-2),2) - 4*yellow)) / 2;
    int b = (tmp < brown/2 - 2 - tmp? tmp : ((brown/2-2) - sqrt(pow((brown/2-2),2) - 4*yellow)) / 2);
    int a = brown/2 - 2 - b;
    return vector<int>{a+2, b+2};
}




